#include <stdio.h>
unsigned invert(unsigned x,int p,int n);

int main()
{
    unsigned x;
    int p;
    int n;
    printf("Enter number to invert:");
    scanf("%d",&x);
    printf("Enter the start position to invert from p :");
    scanf("%d",&p);
    printf("Enter the no of bits n:");
    scanf("%d",&n);
    
    printf("%u\n",invert(x,p,n));
    return 0;
}
unsigned invert(unsigned x,int p,int n)
{
    return x ^ (~(~0<<n)<< p);
}
