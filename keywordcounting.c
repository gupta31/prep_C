#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100

int getword(char*,int);
int binsearch(char *,struct key *,int);

struct key{
    char *word;
    int count;
};
int main(){
struct key keytab[MAXWORD];
char word[MAXWORD];
int n;
int nkeys;
nkeys=sizeof(keytab)/sizeof(struct key);
while(getword(word,MAXWORD)!=EOF)
    if(isalpha(word[0]))
        if((n=binsearch(word,keytab,nkeys))>=0)
           keytab[n].count++;
for(n=0;n<nkeys;n++)
{
    if(keytab[n].count>0)
    printf("%4d %s\n",keytab[n].count,keytab[n].word);
}

return 0;
}
int binsearch(char*word,struct key tab[],int n){
    int cond;
    int low,mid,high;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if((cond=strcmp(word,tab[mid].word))<0)
            high=mid-1;
        else if(cond>0)
            low=mid+1;
        else{
                return mid;
            }
    }
  return -1;
}
int getword(char*word,int lim){
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
