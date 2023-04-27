#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int len = sizeof(arr) / sizeof(int);
double sum = 0;

void* add_first_half(void* arg) { 
    for (int i = 0; i < len / 2; i++) { 
        sum += arr[i];
    }
    return NULL;
}

void* add_second_half(void* arg) {
    for (int i = len / 2; i < len; i++) {
        sum += arr[i];
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, add_first_half, NULL); 
    pthread_create(&t2, NULL, add_second_half, NULL);
    pthread_join(t1, NULL); 
    pthread_join(t2, NULL);
    printf("The sum of all elements in the array is: %.2f\n", sum);
    return 0;
}
