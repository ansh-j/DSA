#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    while (a--)
    {
        int days, amount;
        scanf("%d %d", &days, &amount);
        int arr[days];
        for (int i = 0; i < days; i++)
        {
            scanf("%d", &arr[i]);
        }
        selectionSort(arr, days);
        int sum = 0;
        int count = days;

        for (int i = days; i > 0; i--)
        {
            if (sum >= amount)
            {
                break;
            }
            if (sum < amount)
            {

                sum += arr[i-1];
                count--;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}