#include <stdio.h>

void input(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int indinsertion(int array[], int capacity, int size, int index, int element)
{
    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }
    array[index] = element;

    return 1;
}

int main()
{
    int size, index, element;
    int arr[10];

    printf("HOW MANY ELEMENTS DO YOU WANT TO ADD:\n");
    scanf("%d", &size);

    input(arr, size);
    display(arr, size);

    printf("ENTER THE INDEX YOU WANT TO INSERT:\n");
    scanf("%d", &index);

    printf("ENTER THE ELEMENT YOU WANT TO INSERT:\n");
    scanf("%d", &element);

    int a = indinsertion(arr, 10, size, index, element);

    if (a == -1)
    {
        printf("INSERTION NOT POSSIBLE !!\n");
    }
    else
    {
        size += 1;
        display(arr, size);
    }
    return 0;
}
