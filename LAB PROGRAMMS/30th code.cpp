
#include <stdio.h>
#include <pthread.h>

void *myThread(void *arg)
{
    printf("Thread running, Thread ID: %lu\n",
           (unsigned long)pthread_self());

    pthread_exit(NULL);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Create two threads
    pthread_create(&t1, NULL, myThread, NULL);
    pthread_create(&t2, NULL, myThread, NULL);

    // Wait for both threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Compare thread IDs
    if (pthread_equal(t1, t2))
        printf("t1 and t2 are the same thread.\n");
    else
        printf("t1 and t2 are different threads.\n");

    return 0;
}

