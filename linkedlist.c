#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void listtraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->next = first;

    first->data = 34;
    first->next = second;

    second->data = 45;
    second->next = third;

    third->data = 45;
    third->next = NULL;

    listtraversal(head);

    return 0;
}
