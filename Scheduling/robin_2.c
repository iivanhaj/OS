#include <stdio.h>  

struct Process
{
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
};

int main()
{
    int n, quantum;
    int completed = 0, currentTime = 0;

    //Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    //Input the arrival and burst time of each process
    printf("Enter the arrival and burst time of each process: ");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    //Input the quantum time
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    while (completed < n)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].rt > 0 && p[i].at <= currentTime)
            {
                done = 0;
                if (p[i].rt > quantum)
                {
                    currentTime += quantum;
                    p[i].rt -= quantum;
                }
                else
                {
                    currentTime += p[i].rt;
                    p[i].rt = 0;
                    completed++;
                    p[i].tat = currentTime - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                }
            }
        }

        if (done)
        {
            currentTime++;
        }
    }

    //Display process details
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    return 0;
}
