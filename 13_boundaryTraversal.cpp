https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node *root)
    {
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        return false;
    }
    void leftboundary(Node *root,vector<int>&ans)
    {
        Node *tmp=root->left;
        while(tmp)
        {
            if(!isLeaf(tmp))
            {
                ans.push_back(tmp->data);
            }
            if(tmp->left)
            {
                tmp=tmp->left;
            }
            else
            {
                tmp=tmp->right;
            }
        }
        // for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i]<<" ";
        // }cout<<endl;
    }
    void rightboundary(Node*root,vector<int>&ans)
    {
        Node *tmp=root->right;
        vector<int>curr;
        while(tmp)
        {
            if(!isLeaf(tmp))
            {
                curr.push_back(tmp->data);
            }
            if(tmp->right)
            {
                tmp=tmp->right;   
            }
            else
            {
                 tmp=tmp->left;
            }
        }
        for(int i=curr.size()-1;i>=0;i--)
        {
            ans.push_back(curr[i]);
        }
        // for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i]<<" ";
        // }cout<<endl;
    }
    void addLeaves(Node *root,vector<int>&ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            
            return;
        }
        if(root->left)addLeaves(root->left,ans);
        if(root->right)addLeaves(root->right,ans);
        // for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i]<<" ";
        // }cout<<endl;
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(!root)return ans;
         if (!isLeaf(root)) ans.push_back(root -> data);
        leftboundary(root,ans);
        addLeaves(root,ans);
        rightboundary(root,ans);
        return ans;
    }
};