#include <stdio.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    int priority;
};

void sort(struct Process p[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].priority > p[j].priority || (p[i].priority == p[j].priority && p[i].at > p[j].at))
            {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    int n, currentTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter the arrival, burst time and priority of each process: ");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
    }

    sort(p, n);

    for(int i=0; i<n; i++)
    {
        currentTime = currentTime < p[i].at ? p[i].at : currentTime;
        p[i].wt = currentTime - p[i].at;
        p[i].tat = p[i].wt + p[i].bt;
        currentTime += p[i].bt;
    }

    //Display process details
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }

    return 0;
}