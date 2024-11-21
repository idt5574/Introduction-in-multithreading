#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void *printHello(void* index)
{
    int x = *((int *) index);
    if(x == 0) {
        sleep(5);
    } else if(x == 1)
    {
        sleep(4);
    } else if(x == 2)
    {
        sleep(3);
    } else if(x == 3)
    {
        sleep(2);
    } else if(x == 4)
    {
        sleep(1);
    }

    for(int i = 0; i < 5; i++)
    {   
        printf("THREAD %d: %d\n", x, i);
    }
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    int err;

    for(int t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %d\n", t);
        err = pthread_create(&threads[t], NULL, printHello, &t);
        sleep(1);
    }

    pthread_exit(NULL);
    printf("end");
}