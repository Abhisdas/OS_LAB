#include <stdio.h>
int main()
{
    int n, i, j, total=0, time=0;
    float avg_wt=0, avg_tat=0;
    int burst[10], priority[10], process[10], waiting[10], turnaround[10];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority for Process %d: ",i+1);
        scanf("%d %d",&burst[i],&priority[i]);
        process[i]=i+1; //process number
    }
    //Sorting based on Priority
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(priority[i]>priority[j])
            {
                int temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }
    //Table of results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        waiting[i]=time; //calculate waiting time
        time+=burst[i];
        turnaround[i]=time; //calculate turnaround time
        avg_wt+=waiting[i];
        avg_tat+=turnaround[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i],burst[i],priority[i],waiting[i],turnaround[i]);
    }
    avg_wt/=n; //calculate average waiting time
    avg_tat/=n; //calculate average turnaround time
    printf("\n\nAverage Waiting Time: %f",avg_wt);
    printf("\nAverage Turnaround Time: %f",avg_tat);
    return 0;
}