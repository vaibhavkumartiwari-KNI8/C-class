#include<stdio.h>
int main()
{
    int i, n, ceven = 0, codd = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], even[n], odd[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int evenIndex = 0, oddIndex = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even[evenIndex++] = arr[i];
            ceven++;
        }
        else
        {
            odd[oddIndex++] = arr[i];
            codd++;
        }
    }
    printf("Even number count is: %d\n", ceven);
    printf("Odd number count is: %d\n", codd);
    printf("Even numbers are: ");
    for (i = 0; i < ceven; i++)
    {
        printf("%d ", even[i]);
    }
    printf("\nOdd numbers are: ");
    for (i = 0; i < codd; i++)
    {
        printf("%d ", odd[i]);
    }
    printf("\n");

    
    return 0;
}