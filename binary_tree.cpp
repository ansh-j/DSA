#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *n = NULL;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void pre_order(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->data);

        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(struct node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d\n", root->data);
    }
}
void in_order(struct node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        printf("%d\n", root->data);
        post_order(root->right);
    }
}

int main()
{
    struct node *root = create_node(2);
    struct node *p1 = create_node(1);
    struct node *p2 = create_node(4);
    struct node *p3 = create_node(5);
    struct node *p4 = create_node(7);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    // pre_order(root);
    post_order(root);

       return 0;
}
