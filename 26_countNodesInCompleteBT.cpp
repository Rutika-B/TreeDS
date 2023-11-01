https://leetcode.com/problems/count-complete-tree-nodes/
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
 // A complete binary tree is a special type of binary tree where all the levels of the tree are filled completely except the lowest level nodes which are filled from as left as possible.


    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
          return 0;
        }
        TreeNode* lef=root->left;
        TreeNode* rit=root->right;
        int l=1,r=1;
        while(lef)lef=lef->left,l++;
        while(rit)rit=rit->right,r++;

        if(l==r)return (1<<l)-1;
        //above line return (2^h-1)
        else
        return 1+countNodes(root->left)+countNodes(root->right);    

    }
};