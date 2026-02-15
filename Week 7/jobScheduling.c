#include <stdio.h>
#include <stdlib.h>
#define N 14
struct Job{
    int id;
    int profit;
    int deadline;
};
int compare(const void *a, const void *b){
    struct Job *jobA=(struct Job *)a;
    struct Job *jobB=(struct Job *)b;
    return jobB->profit-jobA->profit;
}
int main(){
    int profits[N]={22,19,29,28,30,21,27,25,24,26,14,27,19,11};
    int deadlines[N]={3,3,8,6,7,5,10,4,6,12,13,2,14,1};
    struct Job jobs[N];
    for(int i = 0; i < N; i++){
        jobs[i].id=i+1;
        jobs[i].profit=profits[i];
        jobs[i].deadline=deadlines[i];
    }
    qsort(jobs,N,sizeof(struct Job),compare);
    int maxDeadline=0;
    for(int i=0;i<N;i++){
        if(jobs[i].deadline>maxDeadline)
            maxDeadline=jobs[i].deadline;
    }
    int slot[maxDeadline+1];
    for (int i=0;i<=maxDeadline;i++)
        slot[i]=-1;
    int totalProfit=0;
    for (int i=0;i<N;i++){
        for (int j=jobs[i].deadline;j>0;j--){
            if(slot[j]==-1){
                slot[j]=jobs[i].id;
                totalProfit+=jobs[i].profit;
                break;
            }
        }
    }
    printf("Scheduled Jobs:\n");
    for (int i=1;i<=maxDeadline;i++){
        if (slot[i]!=-1)
            printf("Time Slot %d -> Job %d\n", i, slot[i]);
    }
    printf("\nTotal Profit = %d\n", totalProfit);
    return 0;
}