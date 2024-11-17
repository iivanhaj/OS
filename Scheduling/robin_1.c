#include <stdio.h>

int main()
{
    int n, quantum;

    //Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], rt[n];
    int completed = 0, currentTime = 0;

    //Input the burst time of each process
    printf("Enter the burst time of each process: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    //Input the quantum time
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);   

    while(completed < n)
    {
        for(int i =0; i<n; i++)
        {
            if(rt[i] > 0)
            {
                if(rt[i] > quantum)
                {
                    currentTime += quantum;
                    rt[i] -= quantum;
                }
                else
                {
                    currentTime += rt[i];
                    rt[i] = 0;
                    completed++;
                    tat[i] = currentTime;
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
    }

    //Display process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}