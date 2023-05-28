#include <stdio.h>

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int binarysearch(int array[], int size, int element)
{
    int low, high, mid;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == element)
        {
            return mid;
        }
        if (array[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {23, 45, 55, 76, 88, 100, 105, 305, 456, 567, 809,908};
    int size = sizeof(arr) / sizeof(int);
    int element = 76;
    display(arr, size);
    int index = binarysearch(arr, size, element);
    printf("THE ELEMENT %d IS PRESENT AT INDEX %d\n", element, index);

    return 0;
}
