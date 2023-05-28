#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
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

int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr) == 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        printf("Stack underflow. Cannot pop from the stack \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;

        return val;
    }
}
int peek(struct stack *ptr, int i)
{
    int ind = ptr->top - i + 1;
    if (ind < 0)
    {
        printf("not a vaild position in the stack\n");
    }
    else
    {
        return ptr->arr[ind];
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("%d\n", isEmpty(sp));
    printf("%d\n", isFull(sp));

    push(sp, 3);
    push(sp, 4);
    push(sp, 343);
    push(sp, 3442);
    push(sp, 44);
    push(sp, 244);
    push(sp, 45);
    push(sp, 6324);
    push(sp, 975);
    push(sp, 894);
    push(sp, 94);

    printf("TOP = %d\n", sp->top);


    printf("%d\n", isEmpty(sp));
    printf("%d\n", isFull(sp));

    printf("Using peek we get %d\n", peek(sp,12));

    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));
    printf("%d was popped\n", pop(sp));

    printf("%d\n", isEmpty(sp));
    printf("%d\n", isFull(sp));
    return 0;
}
