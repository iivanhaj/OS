#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutex, writeblock;
int data = 0, rcount = 0;

void *reader(void *arg)
{
    int reader_id = *(int *)arg;
    sem_wait(&mutex);
    rcount++;

    if (rcount == 1)
    {
        sem_wait(&writeblock);
    }

    sem_post(&mutex);
    printf("Reader %d reads data: %d\n", reader_id, data);

    sem_wait(&mutex);
    rcount--;

    if (rcount == 0)
    {
        sem_post(&writeblock);
    }

    sem_post(&mutex);
    
    return NULL;
}

void *writer(void *arg)
{
    int writer_id = *(int *)arg;
    sem_wait(&writeblock);
    data++;
    printf("Writer %d writes data: %d\n", writer_id, data);
    sem_post(&writeblock);
    
    return NULL;
}

int main()
{
    int r, w;
    printf("Enter the number of readers and writers: ");
    scanf("%d %d", &r, &w);

    pthread_t r_thread[r], w_thread[w];
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);

    //create reader threads
    for (int i = 0; i < r; i++)
    {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&r_thread[i], NULL, reader, id);
    }

    //create writer threads
    for (int i = 0; i < w; i++)
    {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&w_thread[i], NULL, writer, id);
    }

    //Wait for reader threads to finish
    for (int i = 0; i < r; i++)
    {
        pthread_join(r_thread[i], NULL);
    }

    //Wait for writer threads to finish
    for (int i = 0; i < w; i++)
    {
        pthread_join(w_thread[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&writeblock);

    return 0;
}