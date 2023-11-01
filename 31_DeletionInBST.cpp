https://leetcode.com/problems/delete-node-in-a-bst/description/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
          return NULL;
        }
        if(root->val==key)
        {
          return reconstruct(root);
        }
        TreeNode* tmp=root;
        while(tmp)
        {
            if(tmp->val>key)
            {
              if(tmp->left!=NULL && tmp->left->val==key)
              {
                tmp->left=reconstruct(tmp->left);
                break;
              }
              else
              {
                tmp=tmp->left;
              }
            }
            else
            {
              if(tmp->right!=NULL && tmp->right->val==key)
              {
                tmp->right=reconstruct(tmp->right);
                break;
              }
              else
              {
                tmp=tmp->right;
              }
            }
        }
      return root;
    }
    TreeNode* reconstruct(TreeNode* root)
    {
      if(root->left==NULL)
      {
        return root->right;
      }
      if(root->right==NULL)
      {
        return root->left;
      }
      TreeNode* rightChild=root->right;
      TreeNode* rightMost=root->left;
      while(rightMost->right)
      {
        rightMost=rightMost->right;
      }
      rightMost->right=rightChild;
      return root->left;
    }
};