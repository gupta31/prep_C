#include <stdio.h>
#define MAXL   100
void reverse(char s[]);
void itob(int n,char s[],int b);
int main()
{
    char s[MAXL];
    int n;
    int b=16;
    printf("Enter number:");
    scanf("%d",&n);
    itob(n,s,16);
    printf("\n%s",s);
    return 0;
}
void itob(int n,char s[],int b)
{
    int i,sign;
    i=0;
    if((sign=n)<0){
        n=-n;
    }
    do
    {
            int k;
            k=n%b;
            
            if(k<=9)
            {
                s[i++]=k+'0';
            }
            else
                s[i++]=k+'a'-10;
            
            
    }while((n/=b)>0);
    if(sign<0)
    {
        s[i++]='-';
       
    }
    s[i]='\0';
    reverse(s);
}
void reverse(char s[]){
    int i,j,temp;
    for(i=0,j=my_strlen(s)-1;i<j;i++,j--)
    {
        
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}
int my_strlen(char s[]){
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}