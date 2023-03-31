#include<stdio.h>

int main() {
    int n,i,bt[20],at[20],wt[20],tat[20],avwt=0,avtat=0;
    printf("Enter total number of processes (maximum 20): ");
    scanf("%d",&n);
    printf("\nEnter Process Burst Time and Arrival Time:\n");
    for(i=0;i<n;i++) {
        printf("P[%d]:",i+1);
        scanf("%d %d",&bt[i],&at[i]);
    }
    //sorting based on arrival time
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(at[i] > at[j]) {
                int temp_bt = bt[i];
                int temp_at = at[i];
                bt[i] = bt[j];
                at[i] = at[j];
                bt[j] = temp_bt;
                at[j] = temp_at;
                 }
        }
    }
    wt[0]=0;    //waiting time for first process is 0
    //calculating waiting time
    for(i=1;i<n;i++){
        wt[i]=0;
        for(int j=0; j<i; j++) {
            wt[i]+=bt[j];
        }
        wt[i]-=at[i];
    }
    printf("\nProcess\t Burst Time\t Arrival Time\t Waiting Time\t Turnaround Time");
    //calculating turnaround time
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t %d\t\t %d\t\t%d\t\t\t%d",i+1,bt[i],at[i],wt[i],tat[i]);
    }
     avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
    return 0;
}