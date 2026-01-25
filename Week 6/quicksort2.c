#include <stdio.h>
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
void quickSortLast(int a[],int low,int high){
    if (low<high){
        int p=partitionLast(a,low,high);
        quickSortLast(a,low,p-1);
        quickSortLast(a,p+1,high);
    }
}
int main(){
    int a[]={157,110,147,122,111,149,151,141,123,112,117,133};
    int n=12;
    quickSortLast(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}