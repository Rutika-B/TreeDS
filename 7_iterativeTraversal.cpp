#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void preorderIterative(node *h)
{
    if (h == NULL)
    {
        return;
    }
    stack<node *> s;
    stack<int>path;
    s.push(h);
    path.push(h->data);
    while (!s.empty())
    {
        node *top = s.top();
        cout << top->data << " ";
        s.pop();
        if (top->right != NULL)
        {
            s.push(top->right);
        }
        if (top->left != NULL)
        {
            s.push(top->left);
        }
        if(top->left==NULL && top->right==NULL)
        {
            
        }
    }
}
void InorderIterative(node *h)
{
    if (h == NULL)
    {
        return;
    }
    stack<node *> s;
    vector<int> ds;
    while (true)
    {
        if (h)
        {
            s.push(h);
            h = h->left;
        }
        else
        {
            if (s.empty())
            {
                break;
            }
            node *p = s.top();
            cout << p->data << " ";
            h = p->right;
            s.pop();
        }
    }
}
int main()
{
    node *head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->left->left = new node(4);
    head->left->right = new node(5);
    head->right->left = new node(6);
    head->right->right = new node(7);

    preorderIterative(head);
    cout << endl;
    InorderIterative(head);

    return 0;
}