#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isfull(struct stack *ptr)
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
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
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
    if (isfull(ptr) == 1)
    {

        printf("STACK OVERFLOW!!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isempty(ptr) == 1)
    {
        printf("STACK UNDERFLOW!!\n");
    }
    else
    {
        char x = ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}
int compare(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesismatching(char *exp)
{
    struct stack *n;
    n->size = strlen(exp);
    n->top = -1;
    n->arr = (char *)malloc(n->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(n, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            char popped_ch = pop(n);
            if (!compare(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isempty(n))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *a = "(3*4{34}3424[343+34])";
    if (parenthesismatching(a))
    {
        printf("PARENTHESIS IS MATCHED!!\n");
    }
    else
    {
        printf("PARENTHESIS IS NOT MATCHED!!\n");
    }
    
    return 0;
}
