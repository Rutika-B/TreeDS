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
//////---------------------------recursive method-----------------------------------------
// struct node *search(struct node *n, int key)
// {
//     if (n == NULL)
//     {
//         return NULL;
//     }
//     else if (n->data == key)
//     {
//         return n;
//     }
//     else if (n->data > key)
//     {
//         return search(n->left, key);
//     }
//     else
//     {
//         return search(n->right, key);
//     }
// }
//////---------------------------iterative method-----------------------------------------

struct node *search(struct node *n, int key)
{
    struct node *tmp = n;
    while (tmp != NULL)
    {
        if (tmp->data == key)
        {
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
    return NULL;
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

    if (search(r, 20) == NULL)
    {
        cout << "element is not found" << endl;
    }
    else
    {
        cout << "found" << endl;
    }

    return 0;
}