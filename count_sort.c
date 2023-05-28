#include <stdio.h>

void countsort(int arr[], int n, int max)
{
    int m = max + 1;
    int a[m];
    for (int i = 0; i < m+1; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        a[arr[i]]++;
    }
    int j = 0;
    int i = 0;
    while (i <= max)
    {
        if (a[i] > 0)
        {
            arr[j] = a[i];
            j++;
            a[i]--;
        }
        else
        {
            i++;
        }
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    //    9 1 4 14 4 15 6
    int n;
    printf("ENTER THE SIZE OF THE ARRAY:\n");
    scanf("%d", &n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printarray(arr, n);
    countsort(arr, n, max);
    printarray(arr, n);

    return 0;
}
