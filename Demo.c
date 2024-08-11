#include<stdio.h>
int main()
{
    int i=0,j,k;
    j = ++i;
    k = j++;
    printf("%d %d %d",i++,++j,k--);
    return 0;
}