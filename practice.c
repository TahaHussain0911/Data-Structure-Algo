#include <stdio.h>
int main()
{
    const int len=2;
    int a[len];
    a[0]=2;
    a[1]=3;
    int ptr=&a[1];
    ptr+=4;
    // *ptr+=4;
    printf("Address: %u,Value: %d",&a[0],a[0]);
    printf("Address: %u,Value: %d",&a[1],a[1]);
    printf("Address: %u,Value: %d",ptr,a[2]);
    // printf("Address: %u,Value: %d",&a[5],a[5]);
  
    return 0;
}