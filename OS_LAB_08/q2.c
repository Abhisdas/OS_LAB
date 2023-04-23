#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void print_array(void *arg) {

int i;

int arr (int *)arg; for (i = 0; i < ARRAY_SIZE; i++) {

printf("%d ", arr[i]);

}

printf("\n");

return NULL;



}

int main() {

pthread_t tid;

pthread_create(&tid, NULL, print_array, array); pthread_join(tid, NULL);

return 0;

}