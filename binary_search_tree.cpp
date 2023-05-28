#include <bits/stdc++.h>

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
        in_order(root->left);
        printf("%d\n", root->data);
        in_order(root->right);
    }
}

int is_bst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!is_bst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return is_bst(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        // cout << "ELEMENT NOT FOUND" << endl;
        // printf("ELEMENT NOT FOUND\n");
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Could not insert %D; Element already exists\n", key);
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }  
    struct node *temp = create_node(key);
    if (key > prev->data)
    {
        prev->right = temp;
    }
    else
    {
        prev->left = temp;
    }
}
struct node *presuccessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletenode(struct node *root, int value)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;    
    }

    if (root->data < value)
    {
        root->right = deletenode(root->right, value);
    }
    else if (root->data > value)
    {
        root->left = deletenode(root->left, value);
    }
    else
    {
        ipre = presuccessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root; 
}

int main()
{
    struct node *root = create_node(5);

    // struct node *p1 = create_node(3);
    // struct node *p2 = create_node(6);
    // struct node *p3 = create_node(1);
    // struct node *p4 = create_node(4);
    // root->left = p1;
    // root->right = p2;
    // p1->left = p3;
    // p1->right = p4;

    // in_order(root);
    // pre_order(root);
    // post_order(root);

    // struct node *val = search(root, 6);
    // if (val == NULL)
    // {
    //     printf("ELEMENT NOT FOUND\n");
    // }
    // else
    // {
    //     printf("%d is present\n", val->data);
    // }

    insert(root, 4);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);

    in_order(root);
    deletenode(root, 3);
    printf("\n");
    in_order(root);
    

    return 0;
}
