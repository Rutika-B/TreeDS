// https://www.interviewbit.com/problems/path-to-given-node/
bool getpath(TreeNode *root, int B, stack<int> &s)
{
    if (root == NULL)
    {
        return false;
    }
    s.push(root->val);
    if (root->val == B)
    {
        return true;
    }

    if (getpath(root->left, B, s) || getpath(root->right, B, s))
    {
        return true;
    }

    s.pop();
    return false;
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    stack<int> s;
    getpath(A, B, s);
    vector<int> v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end());
    return v;
}