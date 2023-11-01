https://leetcode.com/problems/symmetric-tree/
bool check(TreeNode* f,TreeNode* s)
    {
        if(f==NULL && s==NULL)
        {
            return true;
        }
        if((f && s==NULL)|| (s && f==NULL))
        {
            return false;
        }
        if(f->val!=s->val)
        {
            return false;
        }
        return check(f->left,s->right)&& check(f->right,s->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }