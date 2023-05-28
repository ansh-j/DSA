#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{    int n = low+high+1;
    int i, j, k, b[n];
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    for (int a = low; a <= high; a++)
    {
        arr[a] = b[a];
    }
}

void mergesort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    printarray(arr,n);
    mergesort(arr, 0, n - 1);
    printarray(arr,n);

    return 0;
}


