https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
            {
              parent_track[node->left]=node;
                q.push(node->left);
                
            }
            if(node->right)
            {
              parent_track[node->right]=node;
              q.push(node->right);
              
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        traversal(root,parent_track);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=1;
        int distance=0;
        while(!q.empty())
        {
          //if(distance++ == k)break;
          distance++;
          int l=q.size();
          for(int i=0;i<l;i++)
          {
             TreeNode* node=q.front();
             q.pop();
             if(node->left && !visited[node->left])
             {
               q.push(node->left);
               visited[node->left]=1; 
             }
             if(node->right && !visited[node->right])
             {
               q.push(node->right);
               visited[node->right]=1;
             }
             if(parent_track[node] && !visited[parent_track[node]])
             {
               q.push(parent_track[node]);
               visited[parent_track[node]]=1;
             }
          }
        }
        vector<int>ans;
        while(!q.empty())
        {
          ans.push_back(q.front()->val);
          q.pop();
        }
        cout<<distance-1<<endl;
        return ans;
    }
};