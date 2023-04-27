#include<stdio.h>
#include<pthread.h>

int a = 3;

void* f10() {
    for(int i = 0; i < 10; i++) {
        a++;
    }
    printf("Hello World\n");
    return NULL;
}

int main() {
    pthread_t th1, th2;
    pthread_create(&th1, NULL, f10, NULL); 
    pthread_create(&th2, NULL, f10, NULL); 
    pthread_join(th1, NULL); 
    pthread_join(th2, NULL); 
    printf("%d\n", a); 
    printf("main terminates\n");
    return 0;
}
