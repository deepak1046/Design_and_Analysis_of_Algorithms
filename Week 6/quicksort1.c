#include <stdio.h>
int partitionFirst(int a[],int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    while(1){
        while(i<=high&&a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        } else
            break;
    }
    a[low]=a[j];
    a[j]=pivot;
    return j;
}
void quickSortFirst(int a[],int low,int high){
    if(low<high){
        int p=partitionFirst(a,low,high);
        quickSortFirst(a,low,p-1);
        quickSortFirst(a,p+1,high);
    }
}
int main(){
    int a[]={157,110,147,122,111,149,151,141,123,112,117,133};
    int n=12;
    quickSortFirst(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}