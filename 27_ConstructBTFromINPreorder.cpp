https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inmap;
        for(int i=0;i<inorder.size();i++)
        {
            inmap[inorder[i]]=i;
        }
        TreeNode* root=construction(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
    TreeNode* construction(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&inmap)
    {
      if(preStart>preEnd || inStart>inEnd)return NULL;

      TreeNode* root= new TreeNode(preorder[preStart]);

      int indexOfRoot=inmap[root->val];

      int preNext=indexOfRoot-inStart;

      root->left=construction(preorder,preStart+1,preStart+preNext,inorder,inStart,indexOfRoot-1,inmap);
      root->right=construction(preorder,preStart+preNext+1,preEnd,inorder,indexOfRoot+1,inEnd,inmap);
      return root;


    }
};