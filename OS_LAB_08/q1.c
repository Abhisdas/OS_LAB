#include<stdio.h>
#include<pthread.h>



void aythread_function()

{

printf("I am a thread\n");
}

int main() {

printf("Program started\n");

pthread_t th1, th2;

pthread_create(&th1, NULL, mythread_function, NULL); 
pthread_create(&th2, NULL, mythread_function, NULL);

pthread_join(th1, NULL); 
pthread_join(th2, NULL);

printf("Program finished\n");

return 0;
}