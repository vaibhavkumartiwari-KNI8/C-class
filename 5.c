#include <stdio.h>
#include <limits.h>

int main() 
{
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    
    if (n < 2)
     {
        printf("Array must have at least two elements.\n");
        return 1;
     }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
     {
        scanf("%d", &arr[i]);
     }

    int first = INT_MIN, second = INT_MIN;

    for (i = 0; i < n; i++)
     {
        if (arr[i] > first)
         {
            second = first;
            first = arr[i];
         } 
          else if (arr[i] > second && arr[i] != first) 
        {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
    {
        printf("There is no second largest element (all elements may be equal).\n");
    } 
    else 
    {
        printf("The second largest element is %d\n", second);
    }

    return 0;
}
