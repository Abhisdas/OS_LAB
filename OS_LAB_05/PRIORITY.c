#include<stdio.h>
int main(){
  int n,i,j,temp,bt[20],wt[20],tat[20],p[20];
  float avwt=0,avtat=0;
  printf("enter total number of processes(maximum 20):");
  scanf("%d",&n);
  printf("\nEnter Process Burst Time\n");
  for(i=0;i<n;i++){
  printf("P[%d]:",i+1);
  scanf("%d",&bt[i]);
  p[i]=i+1;           //contains process number
    }
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                temp=bt[j];
                bt[j]=bt[i];
                bt[i]=temp;
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }
    wt[0]=0;                    //waiting time for first process is 0
    //calculating waiting time
    for(i=1;i<n;i++){
        wt[i]=0;
        for(int j=0; j<i; j++) {
            wt[i]+=bt[j];
        }
    }
    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time");
    //calculating turnaround time
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t %d\t\t %d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%.2f",avwt);
    printf("\nAverage Turnaround Time:%.2f",avtat);
    return 0;
}