https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
        {
            return v;
        }
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>nodes;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int x=it.second.first;
            int y=it.second.second;
            nodes[x][y].insert(node->val);
            if(node->left)
            {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }
        
        for(auto &i:nodes)
        {
            vector<int>ds;
            for(auto &j:i.second)
            {
                ds.insert(ds.end(),j.second.begin(),j.second.end());
            }
            v.push_back(ds);
        }
        return v;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};
