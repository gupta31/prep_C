#include<stdio.h>
#define HASHSIZE 100

struct nlist{
    struct nlist*next;
    char *name;
    char *defn;
};
char *my_strdup(char *);
static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s){
    unsigned hashvalue;
    for(hashval=0;*s!='\0';s++)
        hashvalue=*s +31*hashval;
    return hashvalue%HASHSIZE;
}
struct nlist *lookup(char *s){
   struct nlist *np;
   for(np=hastab[hash(s)];np!=NULL;np=np->next)
        if(strcmp(s,np->name)==0)
            return np;
   return NULL;
}
char *my_strdup(char *s){
    char*p;
    p=(char*)malloc(strlen(s)+1);
    if(s!=NULL){
        strcpy(p,s);
    }
    return p;
}
struct nlist *install(char *name,char *defn)
{
    struct nlist*p;
    unsigned hashval;
    if(p=lookup(name)==NULL)
        p=(struct nlist*)malloc(sizeof(*p));
        if(np==NULL ||(np->name=my_strdup(name))==NULL)
            return NULL;
        hashval=hash(name);
        p->next=hashtab[hashval];
        hashtab[hashval]=p;
        else{
            free((void*)p->defn);
        }
        if((p->defn=strdup(defn))==NULL)
            return NULL;
        return p;


};
