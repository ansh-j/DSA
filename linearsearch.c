#include <stdio.h>

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int linearsearch(int array[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 4, 67, 3, 67, 87, 26, 7, 734, 723, 7, 373, 2, 77};
    int size = sizeof(arr) / sizeof(int);
    int element = 555;
    display(arr, size);
    int index = linearsearch(arr, size, element);
    printf("THE ELEMENT %d IS PRESENT AT INDEX %d\n",element,index); 

    return 0;
}
