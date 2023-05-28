#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void listtraversal(struct node *ptr)
{
    struct node *head = ptr;

    do   
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;

    } while (ptr != head);

}
struct node *insertatfirst(struct node *head, int data)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;

    return head;
}
struct node *insertafternode(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;
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
    fourth->next = head;

    printf("LINKED LIST BEFORE INSEERTION:\n");
    listtraversal(head);

    printf("LINKED LIST AFTER INSERTION:\n");
    head = insertatfirst(head, 78);
    // head = insertatindex(head, 88, 2);
    listtraversal(head);
    // head = insertatend(head, 100);
    // head = insertafternode(head, second, 99);
    listtraversal(head);

    return 0;
}
