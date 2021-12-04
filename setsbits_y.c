#include <stdio.h>
unsigned setbits(unsigned x,int p,int n,unsigned y);

int main()
{
    unsigned x;
    int p;
    int n;
    unsigned y;
    printf("Enter number to set bits:");
    scanf("%d",&x);
    printf("Enter the start position to set bits from p :");
    scanf("%d",&p);
    printf("Enter the no of bits n:");
    scanf("%d",&n);
    printf("Enter the no of bits y:");
    scanf("%d",&y);
    printf("%u\n",setbits(x,p,n,y));
    return 0;
}
unsigned setbits(unsigned x,int p,int n,unsigned y)
{
    return (x & ((~0 << p))|(~(~0<<(p-n))))|((y & ~(~0<<n))<<(p-n));
}