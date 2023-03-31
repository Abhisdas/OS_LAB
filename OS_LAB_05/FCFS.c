#include<stdio.h>
int main()
{
    int n, i, j, total=0, time=0, smallest, process[10];
    float avg_wt, avg_tat;
    int burst[10], waiting[10], turnaround[10];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time for Process %d: ",i+1);
        scanf("%d",&burst[i]);
        process[i]=i+1; //process number
    }
    //SRTF Algorithm
    burst[9]=9999; //handling case of idle CPU
    for(time=0;total!=n;time++) //incrementing time until all processes are done
    {
        smallest=9;
        for(i=0;i<n;i++) //finding smallest burst time process
        {
            if(burst[i]<burst[smallest] && burst[i]>0)
                smallest=i;
        }
        burst[smallest]--; //decrementing burst time
        if(burst[smallest]==0)
        {
            total++;
            turnaround[smallest]=time+1; //calculate turnaround time
            waiting[smallest]=turnaround[smallest]-burst[smallest]; //calculate waiting time
            avg_wt+=waiting[smallest];
            avg_tat+=turnaround[smallest];
        }
    }
    //Table of results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d",process[i],burst[i],waiting[i],turnaround[i]);
    }
    avg_wt/=n; //calculate average waiting time
    avg_tat/=n; //calculate average turnaround time
    printf("\n\nAverage Waiting Time: %f",avg_wt);
    printf("\nAverage Turnaround Time: %f",avg_tat);
    return 0;
}