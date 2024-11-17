#include <stdio.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    int rt;
    int priority;
};

int main()
{
    int n, completed, currentTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    //Input: Arrival, Burst Time and Priority
    printf("Enter the arrival, burst time and priority of each process: ");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].rt = p[i].bt;
    }

    while(completed < n)
    {
        int max_priority = -1, index = -1;

        for(int i =0; i<n; i++)
        {
            if(p[i].rt > 0 && p[i].at <= currentTime && p[i].priority < max_priority)
            {
                max_priority = p[i].priority;
                index = i;
            }
        }

        if(index == -1)
        {
            currentTime++;
            continue;
        }

        p[index].rt--;
        if(p[index].rt == 0)
        {
            completed++;
            p[index].tat = currentTime - p[index].at + 1;
            p[index].wt = p[index].tat - p[index].bt;
        }

        currentTime++;
    }

    //Display process details
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }

    return 0;
}