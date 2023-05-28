#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void listtraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("QUEUE IS FULL!!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    struct node *n = f;
    if (f == NULL)
    {
        printf("QUEUE IS EMPTY !!\n");
    }
    else
    {
        f = f->next;
        int val = n->data;
        free(n);
        return val;
    }
    return -1;
}

int main()
{

    printf("DEQUEUEING ELEMENT %d\n", dequeue());
    enqueue(90);
    enqueue(456);
    enqueue(78);
    enqueue(234);

    listtraversal(f);
    printf("DEQUEUEING ELEMENT %d\n", dequeue());
    listtraversal(f);


    return 0;
}
