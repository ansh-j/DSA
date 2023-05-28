#include <stdio.h>

// SELECTION SORT IS NOT ADAPTIVE
// SELECTION SORT IS NOT STABLE
// SWAPING CAN BE DONE IN MINIMUM NUMBER OF SWAPS

void selectionsort(int *array, int size)
{
    printf("RUNNING SELECTION SORT.....\n");
    int indexofmin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = array[i];
        array[i] = array[indexofmin];
        array[indexofmin] = temp;
    }
}

int main()
{
    int arr[] = {8, 2, 4, 10, 1, 9};
    // int arr[] = {1, 2, 3, 4, 5, 6};

    int size = (sizeof(arr)) / (sizeof(arr[0]));
    // printf("%d", size);
    selectionsort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
