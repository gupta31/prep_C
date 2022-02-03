#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLIMIT 100
#include<string.h>
struct treenode{
    struct treenode*left;
    struct treenode*right;
    char *word;
    int count;
};
struct treenode*addtree(struct treenode*,char*);
void printtree(struct treenode*);
struct treenode*talloc();
int getword(char*,int);
char *my_strdup(char *);
int main(){
    struct treenode* root;
    char word[MAXLIMIT];
    root=NULL;
    while(getword(word,MAXLIMIT)!=EOF)
        if(isalpha(word[0]))
            root=addtree(root,word);
    printtree(root);
return 0;
}
struct treenode*addtree(struct treenode*p,char*w){
    int cond;
    if(p==NULL){
        p=talloc();
        p->word=my_strdup(w);
        p->left=p->right=NULL;
        p->count=1;

    }
    else if((cond=strcmp(w,p->word))==0)
        p->count++;
    else if(cond<0)
        p->left=addtree(p->left,w);
    else{
        p->right=addtree(p->right,w);
    }
return p;
}
void printtree(struct treenode*p){
    if(p!=NULL){
        printtree(p->left);
        printf("%d %s\n",p->count,p->word);
        printtree(p->right);
    }
}
struct treenode*talloc(){
    return (struct treenode*)malloc(sizeof(struct treenode));
}
char *my_strdup(char *s){
    char*p;
    p=(char*)malloc(strlen(s)+1);
    if(s!=NULL){
        strcpy(p,s);
    }
    return p;
}
int getword(char*word,int lim){
    /*int c,i;
    for(i=0;i<lim && (c=getchar())!=EOF && isalpha(c);i++)
    {
        s[i]=c;

    }
    s[i]='\0';
    return i;*/
    int c;
    char *w=word;
    while(isspace(c=getch()))
        ;
    if(c!=EOF)
        *w++=c;
    if(!isalpha(c)){
        *w='\0';
        return c;
    }
    for(;--lim>0;w++)
    if(!isalnum(*w=getch())){
        ungetch(*w);
        break;
    }
    *w='\0';
    return word[0];
}
