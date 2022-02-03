#include<stdio.h>
struct pair{
    int key;
    int value;
    struct pair *next;
};
void display(struct pair arr[],int size);
int main(){
    int size,i,temp,j;
    printf("Enter the size of the table:");
    scanf("%d",&size);
    struct pair hashtable[size];
    while(j<size){
        hashtable[j].next=NULL;
        j++;
    }
    j=0;
    while(j<size){
            hashtable[j].value=-1;j++;

    }
    printf("Enter the elements:");
    for(i=0;i<size;i++){
        scanf("%d",&temp);
        hashtable[temp%size].value=temp;
        hashtable[temp%size].key=temp%size;
    }
    printf("\n");
    display(hashtable,size);
    search(hashtable,size);
    insert(hashtable,size);
    display(hashtable,size);
    return 0;

}
void display(struct pair arr[],int size){
    printf("Key\tValue\n");
    for(int i=0;i<size;i++){

        printf("%d\t%d\n",arr[i].key,arr[i].value);
        struct pair *ptr;
        ptr=arr[i].next;
        while(ptr!=NULL){
            printf("%d\t",ptr->value);
            ptr=ptr->next;

        }
       printf("\n");
    }
}
void search(struct pair arr[],int size){
    int x;
    printf("Enter the element you want to search:");
    scanf("%d",&x);
    if(arr[x%size].value==x){
        printf("Element exist at %d",x%size);

    }
    else{
        printf("Element does not found");
    }
}
void insert(struct pair arr[],int size){
    int item;
    printf("Enter the element you want to insert:");
    scanf("%d",&item);
    if(arr[item%size].value==-1){
        arr[item%size].value=item;
    }
    else{
        struct pair *ptr;
        ptr= (struct pair *)malloc(sizeof(struct pair *));
        ptr->value=item;
        ptr->next=NULL;
        arr[item%size].next=ptr;

    }

}
