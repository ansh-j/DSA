#include <stdio.h>

void insertionesort(int *array, int size)
{
        int key, j;
        // loop for passes
        for (int i = 1; i < size; i++)
        {
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
}

int main()
{
    int arr[] = {8, 2, 4, 10, 1, 9};
    // int arr[] = {1, 2, 3, 4, 5, 6};

    int size = (sizeof(arr)) / (sizeof(arr[0]));
    // printf("%d", size);
    insertionesort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
