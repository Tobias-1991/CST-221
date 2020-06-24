/*
Zachary Gardner
CST-221
Semaphores

Sources include: https://www.geeksforgeeks.org/use-posix-semaphores-c/
https://stackoverflow.com/questions/33187570/array-of-threads-creation-in-c

I was unable to get the for looping working with creating threads.  Unsure why.
Using semaphores was so simple compared to trying to manage things on our own.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

#define buffer 4
#define getName(var)  #var

int counter;
int i;
void* food(void* arg)
{
    sem_wait(&mutex);
    printf("\nThread Created..\n");


    //critical section
    sleep(1);
}
void* consumeThread(void* arg)
{
    printf("\nConsuming...\n");
    sem_post(&mutex);

}

int main()
{
    sem_init(&mutex, 0, 1);
    for (int i = 0; i < 4; i++)
    {
        pthread_t thread[i];
        pthread_create(&thread[i], NULL, food, NULL);

        sleep(1);
        consumeThread(thread[i]);

    }
    for (int i = 0; i < 4; i++)
    {
        pthread_join("thread[i]", NULL);
        printf("Joining thread ");
        printf("%d", i);
        printf("\n");

    }
    sem_destroy(&mutex);
    pthread_exit(NULL);
}
