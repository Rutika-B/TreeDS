// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v;
   if(root==NULL)
   {
       return v;
   }
   queue<pair<Node*,int>>q;
   map<int,int>m;
   q.push({root,0});
   while(!q.empty())
   {
       auto it=q.front();
       q.pop();
       Node* nod=it.first;
       int flor=it.second;
       if(m.find(flor)==m.end())
       {
           m[flor]=nod->data;
       }
       if(nod->left)
       {
           q.push({nod->left,flor+1});
       }
       if(nod->right)
       {
           q.push({nod->right,flor+1});
       }
   }
   for(auto &i:m)
   {
       v.push_back(i.second);
   }
   return v;
}
