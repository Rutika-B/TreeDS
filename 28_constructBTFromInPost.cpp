https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inmap;
        for(int i=0;i<inorder.size();i++)
        {
            inmap[inorder[i]]=i;
        }
        TreeNode* root=construction(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,inmap);
        return root;
    }
    TreeNode* construction(vector<int>&postorder,int postStart,int postEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&inmap)
    {
      if(postStart<postEnd || inStart>inEnd)return NULL;

      TreeNode* root= new TreeNode(postorder[postStart]);

      int indexOfRoot=inmap[root->val];

      int postNext=inEnd-indexOfRoot;

      root->left=construction(postorder,postStart-postNext-1,postEnd,inorder,inStart,indexOfRoot-1,inmap);
      root->right=construction(postorder,postStart-1,postStart-postNext,inorder,indexOfRoot+1,inEnd,inmap);
      return root;


    }
};