https://practice.geeksforgeeks.org/problems/burning-tree/1
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* traversal(Node* root,int target,unordered_map<Node*,Node*>&parent_track)
    {
        queue<Node*>q;
        q.push(root);
        Node* start;
        while(!q.empty())
        {
            Node* fr=q.front();
            q.pop();
            if(fr->data==target)start=fr;
            if(fr->left)
            {
                q.push(fr->left);
                parent_track[fr->left]=fr;
            }
            if(fr->right)
            {
                q.push(fr->right);
                parent_track[fr->right]=fr;
                
            }
        }
        return start;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here`
        unordered_map<Node*,Node*>parent_track;
        Node* start=traversal(root,target,parent_track);
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        q.push(start);
        visited[start]=1;
        int burnSec=0;
        int flag=0;
        while(!q.empty())
        {
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                Node* fr=q.front();
                q.pop();
                if(fr->left && !visited[fr->left])
                {
                    q.push(fr->left);
                    visited[fr->left]=1;
                    flag=1;
                }
                if(fr->right && !visited[fr->right])
                {
                    q.push(fr->right);
                    visited[fr->right]=1;
                    flag=1;
                }
                
                if(parent_track[fr] && !visited[parent_track[fr]])
                {
                    q.push(parent_track[fr]);
                    visited[parent_track[fr]]=1;
                    flag=1;
                }
            }
            if(flag) burnSec++;
            flag=0;
        }
        return burnSec;
    }
};