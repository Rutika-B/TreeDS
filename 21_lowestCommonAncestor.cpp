TreeNode *getlca(TreeNode *node, TreeNode *p, TreeNode *q)
{
    if (node == NULL || node == p || node == q)
    {
        return node;
    }
    TreeNode *left = getlca(node->left, p, q);
    TreeNode *right = getlca(node->right, p, q);
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        return node;
    }
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return getlca(root, p, q);
}
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/