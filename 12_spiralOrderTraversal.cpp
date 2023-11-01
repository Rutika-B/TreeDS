https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

class Solution {
public:
    vector<vector<int>> zigzag(TreeNode* root,vector<vector<int>>&ans)
    {
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty())
        {
            int l=q.size();
            vector<int>ds;
            for(int i=0;i<l;i++)
            {
                TreeNode* tmp=q.front();
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
                ds.push_back(tmp->val);
                q.pop();
            }
            if(flag==0)
            {
                ans.push_back(ds);
                flag=1;
            }
            else
            {
                reverse(ds.begin(),ds.end());
                ans.push_back(ds);
                flag=0;
            }
        }
        return ans;
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        return zigzag(root,ans);
    }
};