#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define N 5

sem_t full, empty;
int buffer[N], in = 0, out = 0;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    int items = *(int*)arg;
    for (int i = 0; i < items; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % N;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *arg)
{
    int items = *(int*)arg;
    for (int i = 0; i < items; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % N;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main()
{
    int p_count, c_count;
    printf("Enter the number of items to produce and consume: ");
    scanf("%d %d", &p_count, &c_count);

    pthread_t p_thread, c_thread;
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, N);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p_thread, NULL, producer, &p_count);
    pthread_create(&c_thread, NULL, consumer, &c_count);

    pthread_join(p_thread, NULL);
    pthread_join(c_thread, NULL);

    sem_destroy(&full);
    sem_destroy(&empty);
    pthread_mutex_destroy(&mutex);

    return 0;

}