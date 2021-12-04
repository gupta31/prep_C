

#include <stdio.h>
int htoi(char *s);

int main()
{
   char s[100];
   printf("Enter hexadecimal number:");
   scanf("%[^\n]s",s);////we can use also gets(s);
   printf("\nEquivalent Integer value of hex %s is %d\n", s, htoi(s));

    return 0;
}
int my_strlen(char s[]){
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}
int htoi(char *s){
    int i=0;
    int result=0;
    if(s[i]=='0'){
        i++;
    
        if(s[i]=='x' || s[i]=='X')
        {
            i++;
        }
    }
    for(;i<my_strlen(s);i++){
        result*=16;
        if(s[i]>='0' && s[i]<='9'){
            result=result+s[i]-'0';
        }
        if(s[i]>='A' && s[i]<='F'){
            result=result+s[i]-'A'+10;
        }
        if(s[i]>='a' && s[i]<='f'){
            result=result+s[i]-'a'+10;
        }
    }
   return result; 
}