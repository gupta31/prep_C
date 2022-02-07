#include<stdio.h>
#include<malloc.h>
struct node{
    struct node*left;
    struct node*right;
    int data;
};
struct node*createNode(int data){
struct node*n;
n=(struct node*)malloc(sizeof(struct node));
n->data=data;
n->left=NULL;
n->right=NULL;
return n;
};
void preorder(struct node*root){
    if(root!=NULL){
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
    }

}
void postorder(struct node*root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);

    }
}
void inorder(struct node*root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);


    }
}
int isBST(struct node*root){
    static struct node*prev=NULL;
    if(root!=NULL){
             if(!isBST(root->left))
                return 0;

             if(prev!=NULL && root->data <= prev->data)
                return 0;



    prev=root;
    return isBST(root->right);
    }
    else
        return 1;//empty bst

}
struct node*search(struct node*root,int key){
    if(root==NULL)
        return NULL;
    if(key==root->data)
        return root;
    else if(root->data>key)
        return search(root->left,key);
    else
        return search(root->right,key);

}
struct node*searchIter(struct node*root,int key){
    while(root!=NULL){
        if(key==root->data)
            return root;
        else if(root->data>key)
            root=root->left;
        else
            return root=root->right;

    }
    return NULL;

}
void insert(struct node *root,int key){
    struct node*prev=NULL;
    while(root!=NULL){
        prev=root;
        if(root->data==key){
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node*new=createNode(key);
    if(key<prev->data){
            prev->left=new;

    }
    else{
        prev->right=new;
    }
}
struct node*inorderPredecessor(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
  return root;
}
struct node*deleteNode(struct node *root,int value){
    struct node*inPre;
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL){//leaf node
        free(root);
        return NULL;
    }
    if(value<root->data){
       root->left=deleteNode(root->left,value);
    }
    else if(value>root->data){
       root->right=deleteNode(root->right,value);
    }
    else{
        inPre=inorderPredecessor(root);//root main root nhi hai everytime it changes
        root->data=inPre->data;
        root->left=deleteNode(root->left,inPre->data);//Predecessor left side me hi milega
    }
    return root;
}
int main(){
    struct node*p=createNode(5);
    struct node*p1=createNode(3);
    struct node*p2=createNode(6);
    struct node*p3=createNode(1);
    struct node*p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    printf("\n");
    printf("%d",isBST(p));
    //insert(p,7);
    //printf("%d",p->right->right->data);
    //printf("\n");
    //preorder(p);
    printf("\n");
    deleteNode(p,6);
    printf("After deletion:\n");
    inorder(p);
return 0;
}
