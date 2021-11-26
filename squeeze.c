#include <stdio.h>
#define MAXLEN    100
void squeeze(char s1[],char s2);

int main(){
	char s1[MAXLEN];
    char s2;
    printf("Write String1:");
    gets(s1);////we can use also gets(s1);
    printf("\nWrite char:");
    scanf("%c",&s2);////we can use also gets(s2);
    squeeze(s1,s2);
	printf("\nSqueezing s1:%s",s1);
	return 0;
}
void squeeze(char s1[],char s2){
	int i,j;
	for(i=j=0;s1[i]!='\0';i++)
	{
		if(s1[i]!=s2){
			s1[j]=s1[i];
		j++;
		}
		
	}
	s1[j]='\0';
		
}