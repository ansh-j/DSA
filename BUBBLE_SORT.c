#include <stdio.h>

// COMPARE TWO ADJACENT ELEMENTS UNTIL THE LARGEST ELEMENT IS AT THE END
void bubblesort(int *array, int size)
{
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            isSorted = 1;
            if (array[j] > array[j + 1])
            {
                int x = array[j];
                array[j] = array[j + 1];
                array[j + 1] = x;
                isSorted = 0;
            }
            if (isSorted == 1)
            {
                return;
            }
        }
    }
}

int main()
{
    // int arr[] = {8, 2, 4, 10, 1, 9};
    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = (sizeof(arr)) / (sizeof(arr[0]));
    // printf("%d", size);
    bubblesort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
