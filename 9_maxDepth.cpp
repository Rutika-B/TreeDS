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
int maxheight(node *h)
{
    if(h==NULL)
    {
        return 0;
    }
    int l=maxheight(h->left);
    int r=maxheight(h->right);
    return 1+max(l,r);
}
int isbalancedBT(node *h)
{
    if(h==NULL)
    {
        return 0;
    }
    int l=maxheight(h->left);
    int r=maxheight(h->right);
    if(abs(l-r)>1)
    {
        return 0;
    }
    return 1+max(l,r);
}
int main()
{
    node *head = new node(1);
    // head->left = new node(2);
    head->right = new node(3);
    // head->left->left = new node(4);
    // head->left->right = new node(5);
    // head->right->left = new node(6);
    head->right->right = new node(7);
    cout<<maxheight(head);
    cout<<endl;
    if (isbalancedBT(head))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"NO";
    }
    

    return 0;
}