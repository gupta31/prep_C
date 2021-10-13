#include<stdio.h>
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr,int n){
    for(int i=0;i<=n-1;i++)
    {
        int temp,minIndex;
        minIndex=i;
        for(int j=i+1;j<n;j++)
        {
           if(arr[j]<arr[minIndex]) 
           {
               minIndex=j;
           }
        }
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
 
}


int main(){
    
    int arr[]={12,54,65,7,23,9};
    int n=6;
    printArray(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}
