#include <stdio.h>

int main()
{
    int n, completed = 0, currentTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], rt[n];
    int total_wt = 0, total_tat = 0;

    printf("Enter the arrival and burst time of each process: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while(completed < n)
    {
        int min_bt = 9999, index = -1;

        for(int i =0; i<n; i++)
        {
            if(rt[i]> 0 && at[i] <= currentTime && rt[i] < min_bt)
            {
                min_bt = rt[i];
                index = i;
            }
        }

        if(index == -1)
        {
            currentTime++;
            continue;
        }

        rt[index]--;
        if(rt[index] == 0)
        {
            completed++;
            tat[index] = currentTime - at[index] + 1;
            wt[index] = tat[index] - bt[index];
            total_tat += tat[index];
            total_wt += wt[index];
        }

        currentTime++;
    }

    //Display process details
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    //Calculate average times
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);

    return 0;
}