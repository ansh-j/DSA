#include <stdio.h>
#include <stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void constructarray(struct myarray *a, int t_size, int u_size)
{
    (*a).total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int));
}

void input(struct myarray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("ENTER THE %d ELEMENT\n", i + 1);
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

void show(struct myarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("THE %d ELEMENT IS:\n", i + 1);
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    int max, used;
    struct myarray marks;
    printf("ENETR THE TOATAL SIZE OF ARRAY YOU WANT:\n");
    scanf("%d", &max);
    printf("ENTER THE SIZE YOU WANNA USE:\n");
    scanf("%d", &used);
    constructarray(&marks, max, used);
    input(&marks);
    show(&marks);

    return 0;
}
