#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int item)
    {
        data = item;
        left = NULL;
        right = NULL;
    }
};
struct node *insert(struct node *root, int key)
{
    struct node *tmp = root;
    struct node *prev = NULL;
    while (tmp != NULL)
    {
        prev = tmp;
        if (tmp->data == key)
        {
            cout << "Element is already exist in tree" << endl;
            return tmp;
        }
        else if (tmp->data > key)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }
    node *nw = new node(key);
    if (prev->data > key)
    {
        prev->left = nw;
    }
    else
    {
        prev->right = nw;
    }
    return nw;
}
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Inorder(root->left);
        Inorder(root->right);
    }
}
int main()
{
    // constructing nodes
    node *r = new node(12);
    node *a1 = new node(8);
    node *a2 = new node(15);
    node *b1 = new node(4);
    node *b2 = new node(10);
    node *c1 = new node(13);
    node *c2 = new node(20);

    //         12
    //       /    \
    //     8      15
    //    / \    /  \
    //   4   10  13  20
    // linking all nodes
    r->left = a1;
    r->right = a2;
    a1->left = b1;
    a1->right = b2;
    a2->left = c1;
    a2->right = c2;

    insert(r, 7);
    insert(r,11);

    //    after insertion
    //               12
    //             /    \
    //           8      15
    //          / \    /  \
    //         4   10  13  20
    //        /
    //       3
    Inorder(r);
    return 0;
}