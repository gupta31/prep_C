#include<stdio.h>
#include<string.h>

void reverseString(char *arr)
{
    char *start;
    char *end;
    char temp;
    start=arr;
    end=arr;
    int n=strlen(arr);
    for(int i=0;i<n-1;i++)
    {
        end++;
    }
    for(int i=0;i<(n/2);i++)
    {
        temp=*end;
        *end=*start;
        *start=temp;
        
        start++;
        end--;
    }
    
}
int main(){
    char arr[]="Sanchi";
    
    reverseString(arr);
    printf("Reverse of this string:%s",arr);
    return 0;
}
