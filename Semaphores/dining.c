#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define N 5

sem_t mutex;
sem_t chopsticks[N];

void *philosopher(void* num)
{
    int id = *(int*)num;

    while(1)
    {
        printf( "Philosopher %d is thinking\n", id);  

        sem_wait(&chopsticks[id]);
        sem_wait(&chopsticks[(id + 1) % N]);

        printf( "Philosopher %d is eating\n", id);

        sem_post(&chopsticks[id]);
        sem_post(&chopsticks[(id + 1) % N]);

        sleep(1);  
    }
}

int main()
{
    pthread_t philosophers[N];
    int id[N];

    sem_init(&mutex, 0, 1);

    for(int i =0; i<N; i++)
    {
        sem_init(&chopsticks[i], 0, 1);
    }

    for(int i =0; i<N; i++)
    {
        id[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &id[i]);
    }

    for(int i =0; i<N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    sem_destroy(&mutex);

    for(int i =0; i<N; i++)
    {
        sem_destroy(&chopsticks[i]);
    }

    return 0;
}