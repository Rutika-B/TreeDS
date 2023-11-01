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
void postorderbyTwostack(node *h)
{
    if (h == NULL)
    {
        return;
    }
    stack<node *> s1;
    stack<node *> s2;
    s1.push(h);

    while (!s1.empty())
    {
        node *tmp = s1.top();
        s1.pop();
        s2.push(tmp);
        if (tmp->left != NULL)
        {
            s1.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            s1.push(tmp->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}
vector<int> postorderbyOneStack(node *h)
{
    vector<int> ans;
    if (h == NULL)
    {
        return ans;
    }
    stack<node *> s;
    s.push(h);
    node *curr = h;
    while (!s.empty() && curr != NULL)
    {
        if (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {

            while (!s.empty() && s.top()->right == NULL)
            {
                ans.push_back(s.top()->data);
                s.pop();
            }

            curr = s.top()->right;
        }
    }
    return ans;
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

    postorderbyTwostack(head);
    vector<int> ds;
    ds = postorderbyOneStack(head);
    for (auto &i : ds)
    {
        cout << i << " ";
    }

    return 0;
}