/* Implementation of a Linked List using a menu */
#include<stdio.h>
#include<stdlib.h>

typedef struct nd {
    int val;
    struct nd *next;
} node;

node *head = NULL;

void traverse();
int search(int item);
int max();
int min();
void reverse();
void my_sort();
void insertStart(int item);
void insertEnd(node *head, int item);
void insertPosition(node *head, int item, int pos);
void deleteStart();
void deleteEnd();
void deletePosition(int pos);

int main(void) {
    int i, opt, item,data,pos;

    while(1) {
        printf("\nTraverse: 1");
        printf("\nSearch: 2");
        printf("\nInsertion at Start: 3");
        printf("\nInsert at End: 4");
        printf("\nInsert at position: 5");
        printf("\nDelete at start: 6");
        printf("\nDelete at end: 7");
        printf("\nDelete at position: 8");
        printf("\nMaximum: 9");
        printf("\nMinimum: 10");
        printf("\nSorting: 11");
        printf("\nReversal: 12");

        printf("\nEnter the option:");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            traverse();
            break;
        case 2:
            printf("\nEnter item to search: ");
            scanf("%d", &item);
            search(item);
            break;
        case 3:
            printf("Enter item to insert:");
            scanf("%d",&item);
            //printf("\nItem entered to insert:%d",item);
            //head=insertStart(head,item);
            //printf("Item has been inserted\n");
            //printf("\n%d",head->val);
            insertStart(item);
            break;
        case 4:
            printf("Enter item to insert at end:");
            scanf("%d",&item);
            insertEnd(head,item);
            break;
        case 5:
            printf("Enter item to insert at pos:");
            scanf("%d",&item);
            printf("Enter pos to insert at:");
            scanf("%d",&pos);
            insertPosition(head,item,pos);
            break;
        case 6:
            deleteStart();
            printf("Head has been deleted from the list");
            break;
        case 7:
            deleteEnd();
            printf("Last node has been deleted from the list");
            break;
        case 8:
            printf("Enter pos to delete at:");
            scanf("%d",&pos);
            deletePosition(pos);
            printf("Node has been deleted from the entered pos of list");
            break;
        case 9:
            printf("Maximum node of list %d",max(head));
            break;
        case 10:
            printf("Minimum node of list %d",min(head));
            break;
        case 11:
            reverse();
            break;
        case 12:
            my_sort();
            break;

        default:
            printf("\nIncorrect option.");
            break;
        }
    }
}

void insertStart(int item) {
    node *temp = (node *)malloc(sizeof(node));
    temp->val = item;
    temp->next = head;
    head=temp;
    return;
}

void traverse() {
    if(head == NULL) {
        printf("\nEmpty Linked List.");
        return;
    } else {
        node *ptr = head;
        while(ptr != NULL) {
            printf("\t%d", ptr->val);
            ptr=ptr->next;
        }
    }
}

int search(int item) {
    node *ptr = head;
    while(ptr != NULL) {
        if(ptr->val == item) {
            return (ptr->val);
        }
        else {
            ptr = ptr->next;
        }
    }
    return -1;
}
void insertEnd(node *head,int item){
    node *temp = (node *)malloc(sizeof(node));
    node *t = (node *)malloc(sizeof(node));
    t=head;
    temp->val=item;
    while(t->next!=NULL){
        t=t->next;

    }
    temp->next=NULL;
    t->next=temp;
}
void insertPosition(node *head, int item, int pos){
    node *temp = (node *)malloc(sizeof(node));
    node *t = (node *)malloc(sizeof(node));
    t=head;

    int i=0;
    while(i!=pos){
        t=t->next;
        i++;
    }
     temp->val=item;
     temp->next=t->next;
     t->next=temp;
}
void deleteStart(){
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    head=head->next;
    free(temp);
}
void deleteEnd(){
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    node*t=head->next;
    while(t->next!= NULL){
        temp=temp->next;
        t=t->next;
    }
    temp->next=NULL;
    free(t);
}
void deletePosition(int pos){
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    node*t=head->next;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
        t=t->next;
    }
    temp->next=t->next;
    free(t);
}
int max(){
    node *temp=head;
    int key=head->val;
    while(temp!=NULL)
    {
        if(key<temp->val)
        {
        key=temp->val;
        temp=temp->next;
        }
    }
    return key;

}
int min(){
    node *temp=head;
    int key=head->val;
    while(temp!=NULL)
    {
        if(key>temp->val)
        {
        key=temp->val;
        temp=temp->next;
        }
    }
    return key;
}
void reverse(){
    node *prev=NULL;
    node *current=head;
    node*next=NULL;
    while(current != NULL){
        next=current->next;//store the next
        current->next=prev;//reverse the direction of linked list
        //aheading the pointers
        prev=current;
        current=next;
    }
    head=prev;
}
void my_sort(){
    node *temp = (node *)malloc(sizeof(node));
    node *t = NULL;
    temp=head;

    while(temp !=NULL){
        t=temp->next;
        while(t!=NULL){
          if(temp->val >t->val)
          {
            int sort;
            sort=temp->val;
            temp->val=t->val;
            t->val=sort;
          }
          t=t->next;
        }

        temp=temp->next;

    }


}
