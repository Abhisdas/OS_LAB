#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10 // size of the buffer

int buffer[BUFFER_SIZE]; // shared buffer between producer and consumer
int in = 0, out = 0; // indices to keep track of the buffer

sem_t empty, full; // semaphores to handle empty and full slots in buffer
pthread_mutex_t mutex; // mutex to protect critical section

// function prototypes
void *producer(void *arg);
void *consumer(void *arg);

int main() {
    // initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // create threads for producer and consumer
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // join threads after completion
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

void *producer(void *arg) {
    int item, i;
    for (i = 0; i < 10; i++) {
        item = rand() % 100; // generate a random item

        sem_wait(&empty); // wait for an empty slot in buffer
        pthread_mutex_lock(&mutex); // enter critical section

        buffer[in] = item; // add item to buffer
        printf("Producer produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE; // increment index (wrap around if needed)

        pthread_mutex_unlock(&mutex); // exit critical section
        sem_post(&full); // signal that buffer is no longer empty
    }
    pthread_exit(0);
}

void *consumer(void *arg) {
    int item, i;
    for (i = 0; i < 10; i++) {
        sem_wait(&full); // wait for a full slot in buffer
        pthread_mutex_lock(&mutex); // enter critical section

        item = buffer[out]; // remove item from buffer
        printf("Consumer consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE; // increment index (wrap around if needed)

        pthread_mutex_unlock(&mutex); // exit critical section
        sem_post(&empty); // signal that buffer is no longer full
    }
    pthread_exit(0);
}
