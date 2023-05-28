#include <stdio.h.>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int IsFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmpty(struct stack *ptr)
{
    if (ptr->top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (IsFull(ptr) == 1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (IsFull(ptr) == 1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        char x = ptr->arr[ptr->top];
        ptr->top--;
    }
}

int parenthisismatching(char *ptr)
{
    struct stack *n;
    n->size = strlen(ptr);
    n->top = -1;
    n->arr = (char *)malloc(n->size * sizeof(char));

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '(')
        {
            push(n, '(');
        }
        else if (ptr[i] == ')')
        {
            if (IsEmpty(n) == 1)
            {
                return 0;
            }
            pop(n);
        }
    }
    if (IsEmpty(n) == 1)
    {
        return 1;
    }
}

int main()
{
    char *exp = "((8)(*--$$9)0))";

    if (parenthisismatching(exp))
    {
        printf("MATCHED!!\n");
    }
    else
    {
        printf("NOT MATCHED!!\n");
    }
    return 0;
}