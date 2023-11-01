#include <bits/stdc++.h>
//MAKECHILDREN SUM-->MEANS each node should be equal to sum of its left n right sum
//to achieve this we can increase node value but can not decrease it
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    };
};
void makeChildrenSum(node *node)
{
    if (node == NULL)
    {
        return;
    }
    int child = 0;
    if (node->left)
    {
        child += node->left->data;
    }
    if (node->right)
    {
        child += node->right->data;
    }
    if (child < node->data)
    {
        if (node->left)
        {
            node->left->data = node->data;
        }
        if (node->right)
        {
            node->right->data = node->data;
        }
    }
    makeChildrenSum(node->left);
    makeChildrenSum(node->right);

    int tot = 0;
    if (node->left)
    {
        tot += node->left->data;
    }
    if (node->right)
    {
        tot += node->right->data;
    }
    if (node->left || node->right)
    {
        node->data = tot;
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}
//Explanation written in book
int main()
{
    struct node *root = new node(40);
    root->left = new node(10);
    root->right = new node(20);
    root->left->left = new node(2);
    root->left->right = new node(5);
    root->right->left = new node(30);
    root->right->right = new node(40);
    root->right->left->left = new node(10);
    root->right->left->right = new node(10);
    makeChildrenSum(root);
    preorder(root);

    return 0;
}