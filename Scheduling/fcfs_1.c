#include <stdio.h>

int main()
{
    int n;

    //Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    //Input the burst time of each process
    printf("Enter the burst time of each process: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    //Calculating waiting time of each process and total waiting time
    //Calculating turnaround time of each process and total turnaround time
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        total_wt += wt[i];
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
    }

    //Displaying process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    //Calculating average waiting time and average turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);

}