#include <stdio.h>

int main()
{
    int n;

    //Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], ct[n];
    int total_wt = 0, total_tat = 0;

    //Input: Arrival and Burst Times
    printf("Enter the arrival and burst time of each process: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &at[i], &bt[i]);
    }

    //calculate completion time 
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    //calculate turnaround time and waiting time
    for(int i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    //Display process details
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    //Calculate average times
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);

    return 0;
}