#include <stdio.h>
#define MAXLEN    100
void my_strcat(char s1[],char s2[]);

int main(){
	char s1[MAXLEN];
    char s2[MAXLEN];
    printf("Write String1:");
    gets(s1);////we can use also gets(s1);
    printf("\nWrite String2:");
    gets(s2);////we can use also gets(s2);
    my_strcat(s1,s2);
	printf("\nConcating s1 and s2:%s",s1);
	return 0;
}
void my_strcat(char s1[],char s2[]){
	int i,j;
	i=j=0;
	while(s1[i]!='\0')
		i++;
	while((s1[i++]=s2[j++]) !='\0')
		
		;
		
}