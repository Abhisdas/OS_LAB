#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
sem_t x,y;
pthread_t tid;
pthread_t writerthreads[100],readerthreads[100];
int readercount;

void *reader(void* param)
{
    sem_wait(&x);
    readercount++;
    if(readercount==1)
    sem_wait(&y);
    sem_post(&x);
    printf("\n%d reader is inside",readercount);
    sem_wait(&x);
    readercount--;
    if(readercount==0)
    {
        sem_post(&y);
    }
    sem_post(&x);
    printf("\n%d Reader is leaving",readercount+1);
}

void *writer(void* param)
{
    printf("\nWriter is trying to enter");
    sem_wait(&y);
    printf("\nWriter has entered");
    sem_post(&y);
    printf("\nWriter is leaving");
}

int main()
{
    int n2,i;
    printf("Enter the number of readers:");
    scanf("%d",&n2);
    int n1[n2];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(i=0;i<n2;i++)
    {
        pthread_create(&writerthreads[i],NULL,reader,NULL);
        pthread_create(&readerthreads[i],NULL,writer,NULL);
    }
    for(i=0;i<n2;i++)
    {
        pthread_join(writerthreads[i],NULL);
        pthread_join(readerthreads[i],NULL);
    }

}