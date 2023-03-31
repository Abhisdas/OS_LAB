#include <stdio.h>
int main()
{
    int n, quanta, i, j, total=0, time=0;
    int burst[10], remaining[10], turnaround[10], waiting[10];
    float avg_wt, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time for Process %d: ",i+1);
        scanf("%d",&burst[i]);
        remaining[i]=burst[i]; //remaining time initially same as burst time
    }
    printf("Enter Time Quanta: ");
    scanf("%d",&quanta); //time slice
    //RR Algorithm
    while(1) //until all processes are done
    {
        int done = 1; //assuming all processes are done
        for(i=0;i<n;i++)
        {
            if(remaining[i]>0)
            {
                done=0; //false
                if(remaining[i]>quanta)
                {
                    time+=quanta;
                    remaining[i]-=quanta;
                }
                else
                {
                    time+=remaining[i];
                    waiting[i]=time-burst[i]; //calculate waiting time
                    remaining[i]=0;
                    avg_wt+=waiting[i];
                    turnaround[i]=time; //calculate turnaround time
                    avg_tat+=turnaround[i];
                }
            }
        }
        if(done==1)
            break; //all processes are done
    }
    //Table of results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d",i+1,burst[i],waiting[i],turnaround[i]);
    }
    avg_wt/=n; //calculate average waiting time
    avg_tat/=n; //calculate average turnaround time
    printf("\n\nAverage Waiting Time: %f",avg_wt);
    printf("\nAverage Turnaround Time: %f",avg_tat);
    return 0;
}