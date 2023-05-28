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

void inddeletion(int array[], int size, int index)
{

    for (int i = index; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
}

int main()
{
    int size, index, element;
    int arr[10];

    printf("HOW MANY ELEMENTS DO YOU WANT TO ADD:\n");
    scanf("%d", &size);

    input(arr, size);
    display(arr, size);

    printf("ENTER THE INDEX YOU WANT TO DELETE:\n");
    scanf("%d", &index);

    inddeletion(arr, size, index);
    size -= 1;

    display(arr, size);

    return 0;
}
