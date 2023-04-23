
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// define the array

int arr[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 int len= sizeof(arr) / sizeof(int);


double sum = 0;

// define a function to add half of the elements from the beginning of the array 
void* add_first_half (void* arg) { 
    for (int i = 0; i < len / 2; i++) { 
        sum += arr[i];

}

return NULL;

}

// define a function to add half of the elements from the end of the array 
void* add_second_half(void* arg) {

for (int i= len / 2; i < len; i++) {

sum += arr[1];

}

return NULL;

}



int main() {

// create the threads pthread_t t1, t2;

pthread_create(&t1, NULL, add_first_half, NULL); pthread_create(&t2, NULL, add_second_half, NULL);

// wait for the threads to finish pthread_join(t1, NULL); pthread_join(t2, NULL);

// print the sum of all the elements in the array printf("The sum of all elements in the array is: %.2f\n", sum);

return 0