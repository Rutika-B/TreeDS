// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *nod = it.first;
        int line = it.second;

        m[line] = nod->data;

        if (nod->left)
        {
            q.push({nod->left, line - 1});
        }
        if (nod->right)
        {
            q.push({nod->right, line + 1});
        }
    }
    for (auto &i : m)
    {
        v.push_back(i.second);
    }
    return v;
}
