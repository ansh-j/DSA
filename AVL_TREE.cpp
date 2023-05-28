#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createnode(int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int balancedfactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }

    return getheight(n->left) - getheight(n->right);
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    y->left = t2;
    x->right = y;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return y;
}

struct node *insert(struct node *n, int key)
{
    if (n == NULL)
    {
        return createnode(key);
    }

    if (key > n->data)
    {
        n->right = insert(n->right, key);
    }
    else if (key < n->data)
    {
        n->left = insert(n->left, key);
    }
    else
    {
        return n;
    }
    n->height = max(getheight(n->left), getheight(n->right)) + 1;
    int b = balancedfactor(n);

    if (b > 1 && n->left->data > key)
    {
        return rightrotate(n);
    }
    if (b < -1 && n->right->data < key)
    {
        return leftrotate(n);
    }
    if (b > 1 && n->left->data < key)
    {
        n->left = leftrotate(n->left);
        return rightrotate(n);
    }
    if (b < -1 && n->right->data > key)
    {
        n->right = rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
}
void in_order(struct node *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

void pre_order(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);

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
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    in_order(root);
    printf("\n");
    pre_order(root);

    return 0;
}
