#include<stdio.h>

void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void merge(int *arr,int low,int mid, int high)
{
    int i,j,k,arr1[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            arr1[k]=arr[i];
            i++;
            k++;
        }
        else{
            arr1[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        arr1[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        arr1[k]=arr[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=arr1[i];
    }
}
void mergeSort(int *arr,int low,int high){
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    
}


int main(){
    
    int arr[]={12,54,65,7,23,9};
    int n=6;
    printArray(arr,n);
    mergeSort(arr,0,5);
    printArray(arr,n);
    return 0;
}
