#include <stdio.h>
#include <stdlib.h>
int partitionLast(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<=pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;
}
int partitionRandom(int a[],int low,int high){
    int r=low+rand()%(high-low+1);
    int temp=a[r];
    a[r]=a[high];
    a[high]=temp;
    return partitionLast(a,low,high);
}
void quickSortRandom(int a[],int low,int high){
    if (low<high){
        int p=partitionRandom(a,low,high);
        quickSortRandom(a,low,p-1);
        quickSortRandom(a,p+1,high);
    }
}
int main(){
    int a[]={157,110,147,122,111,149,151,141,123,112,117,133};
    int n=12;
    quickSortRandom(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}