#include<stdio.h>
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr,int n){
    int j;
    int key=0;
    for(int i=0;i<=n-1;i++)
    {
        key=arr[i];
        j=i-1;
    //Loop for each pass
    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
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
