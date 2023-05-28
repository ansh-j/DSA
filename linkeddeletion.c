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
struct node *deletionatfirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct node *deletionatindex(struct node *head, int index)
{

    struct node *p = head;
    int i = 0;

    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);

    return head;
}

struct node *deletionatend(struct node *head)
{

    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
 
    return head;    
}

struct node *deletionatKey(struct node *head, int key)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->data != key && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == key)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = NULL;

    printf("LINKED LIST BEFORE DELETION:\n");
    listtraversal(head);

    printf("LINKED LIST AFTER DELETION:\n");
    // head = deletionatfirst(head);
    // head = deletionatindex(head, 2);
    // head = deletionatend(head);
    head = deletionatKey(head, 2);

    listtraversal(head);

    return 0;
}
