#include<stdio.h>
int main()
{
    int i,n;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("the elements are:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
   // printf("%d",sum);
    return 0;
}