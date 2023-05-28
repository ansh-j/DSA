#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void listtraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node *top)
{
    if (top == NULL)
    {

        return 1;
    }
}
int isFull(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *top, int data)
{
    if (isFull(top) == 1)
    {
        printf("STACK OVERFLOW!!\n");
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->next = top;
        p->data = data;
        top = p;
        return top;
    }
}
int pop(struct node *top2)
{
    if (isEmpty(top) == 1)
    {
        printf("STACK UNDERFLOW!!\n");
        return -1;
    }
    else
    {
        struct node *n = top2;
        top = top2->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int peek(int index)
{
    struct node *ptr = top;
    for (int i = 0; (i < index - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int stacktop(struct node *ptr)
{
    return top->data;
}

int main()
{

    top = push(top, 3);
    top = push(top, 2);
    top = push(top, 1);
    top = push(top, 0);
    top = push(top, 10);

    listtraversal(top);

    int element = pop(top);
    printf("ELEMENT %d WAS POPPED\n", element);

    listtraversal(top);

    printf("%d is present at 2\n", peek(2));
    printf("%d is the top element \n", stacktop(top));

    return 0;
}
