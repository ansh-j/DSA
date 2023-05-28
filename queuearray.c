#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *n)
{
    if (n->r == n->size - 1)
    {
        return 1;
    }
    return 0;
}
int isempty(struct queue *n)
{
    if (n->f == n->r)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *n, int val)
{
    if (isfull(n) == 1)
    {
        printf("QUEUE IS FULL!!\n");
    }
    else
    {
        n->r++;
        n->arr[n->r] = val;
    }
}
int dequeue(struct queue *n)
{
    if (isempty(n) == 1)
    {
        printf("QUEUE IS EMPTY!!\n");
    }
    else
    {
        n->f++;
        int val = n->arr[n->f];
        return val;
    }
}
void traversal(struct queue *n)
{
    for (int i = n->f+1; i <= n->r; i++)
    {
        printf("%d\n", n->arr[i]);
    }
}

int main()
{
    struct queue *q;
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 23);
    enqueue(q, 3);
    enqueue(q, 45);
    enqueue(q, 93);
    printf("%d WAS DEQUEUED\n", dequeue(q));
    traversal(q);

    return 0;
}
