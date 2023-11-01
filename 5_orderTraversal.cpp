#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int main()
{
    // constructing nodes
    struct node *r = createnode(8);
    struct node *a1 = createnode(45);
    struct node *a2 = createnode(77);
    struct node *b1 = createnode(32);
    struct node *b2 = createnode(86);
    struct node *c1 = createnode(55);
    struct node *c2 = createnode(44);

    //         8
    //       /    \
    //     45     77
    //    / \    /  \
    //   32  86  55   44

    // linking all nodes
    r->left = a1;
    r->right = a2;
    a1->left = b1;
    a1->right = b2;
    a2->left = c1;
    a2->right = c2;

    //  Preorder = root-left-right
    cout << "preorder traversal = ";
    preorder(r);
    cout << endl;

    //  Inorder = left-root-right
    cout << "Inorder traversal = ";
    Inorder(r);
    cout << endl;

    //  Postorder = left-right-root
    cout << "postorder traversal = ";
    postorder(r);
    cout << endl;

    return 0;
}