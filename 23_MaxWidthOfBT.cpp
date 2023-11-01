https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
    queue<pair<TreeNode *,long long>> q;
    q.push({root,0});
    long long mxNodes=1;
    while (!q.empty())
    {
        int l = q.size();
        long long strInd=q.front().second;
        long long EndInd=q.back().second;
        mxNodes=max(mxNodes,EndInd-strInd+1);
        for (int i = 0; i < l; i++)
        {
            TreeNode *fr = q.front().first;
            long long ind=q.front().second-strInd;
            if (fr->left != NULL)
            {
                q.push({fr->left,2LL*ind+1});
            }
            if (fr->right != NULL)
            {
                q.push({fr->right,2LL*ind+2});
            }
            q.pop();
        }
        
      }
      return mxNodes;
    }
};