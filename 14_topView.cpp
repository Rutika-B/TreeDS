https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>v;
    if(root==NULL)
    {
        return v;
    }
    queue<pair<Node*,int>>q;
    map<int,int>m;

    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int line=it.second;
        Node* node=it.first;
        if(m.find(line)==m.end())
        {
            m[line]=node->data;
        }
        if(node->left)
        {
            q.push({node->left,line-1});
        }
        if(node->right)
        {
            q.push({node->right,line+1});
        }
    }
    for(auto &i:m)
    {
        v.push_back(i.second);
    }
    return v;
    }

};
