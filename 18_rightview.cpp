// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
vector<int> rightView(Node *root)
{
    // Your Code here
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
        int flor = it.second;

        m[flor] = nod->data;

        if (nod->left)
        {
            q.push({nod->left, flor + 1});
        }
        if (nod->right)
        {
            q.push({nod->right, flor + 1});
        }
    }
    for (auto &i : m)
    {
        v.push_back(i.second);
    }
    return v;
}