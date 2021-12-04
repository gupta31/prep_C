#include <stdio.h>
#define MAXLEN    100
char *any(char *string1,char *string2);
int main()
{
    char *ptr;
    char s1[MAXLEN];
    char s2[MAXLEN];
    printf("Write String1:");
    scanf("%[^\n]s",s1);////we can use also gets(s1);
    printf("\nWrite String2:");
    scanf("%[^\n]s",s2);////we can use also gets(s2);
    ptr=any(s1,s2);
   
    printf("\nFirst occurance of any character of s2 in s1:%c",*ptr);
   
    return 0;
}

char *any(char *string1,char *string2)
{
    int first_occur=0;
    int flag=0;
    int i,j;
   
    for(i=0;string1[i];i++);
    first_occur=i;
   
    for(i=0;string2[i]!='\0';i++)
    {
        for(j=0;string1[j]!='\0';j++)
        {
            if(string1[j]==string2[i])
            {
               if(j<=first_occur)
                first_occur=j;
                flag=1;
                
               
            }
        }
       
       
    }
    if(flag==1){
        return &string1[first_occur];
    }
    else
    {
        return NULL;
    }
   
}