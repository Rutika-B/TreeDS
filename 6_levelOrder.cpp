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
void levelorder(node *h)
{
    if (h == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(h);
    while (!q.empty())
    {
        node *fr = q.front();
        cout << fr->data << " ";
        q.pop();
        if (fr->left != NULL)
        {
            q.push(fr->left);
        }
        if (fr->right != NULL)
        {
            q.push(fr->right);
        }
    }
}
vector<vector<int>> levelwise(vector<vector<int>> &ans, node *h)
{
    if (h == NULL)
    {
        return ans;
    }
    queue<node *> q;
    q.push(h);
    while (!q.empty())
    {
        int l = q.size();

        vector<int> ds;
        for (int i = 0; i < l; i++)
        {
            node *fr = q.front();
            ds.push_back(fr->data);
            if (fr->left != NULL)
            {
                q.push(fr->left);
            }
            if (fr->right != NULL)
            {
                q.push(fr->right);
            }
            q.pop();
        }
        ans.push_back(ds);
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
    vector<vector<int>>ans;
    levelwise(ans,head);
    for(auto &i:ans)
    {
        for(auto &j:i)
        {
            cout<<j<<" ";
        }cout<<endl;
    }
    bool flag=1;
    flag=!flag;
    
    if (flag==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    

    return 0;
}