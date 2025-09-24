#include<stdio.h>
int main()
{
    int i,n;
    printf("enter the number of elements of the arrays:");

    scanf("%d ",&n);
    int arr[n],brr[n];
    for(i=0;i<n;i++)
    
    {
        scanf("%d",&arr[i]);
        brr[i]=arr[i];
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",brr[i]);
    }
    
    return 0;
}