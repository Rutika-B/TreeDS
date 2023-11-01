https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        {
          return "N";
        }
        queue<TreeNode*>q;
        q.push(root);
        string s="";
        while(!q.empty())
        {
            TreeNode* node=q.front();  
            q.pop();
            if(node==NULL)
            {
              s+="N,";
              continue;
            }
            else
            {
              s+=(to_string(node->val)+",");
            }
            
               q.push(node->left);
          
            
              q.push(node->right);
            

        }
    cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='N')
        {
          return NULL;
        }
        queue<TreeNode*>q;

        stringstream s(data);
        string str;
        getline(s,str,',');
    
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);

        
        
        while(!q.empty())
        {
           TreeNode* a=q.front();
           q.pop();
          getline(s,str,',');
           if(str!="N")
           {
            
             TreeNode* lf=new TreeNode(stoi(str));
             a->left=lf;
             q.push(lf);
           }
           else
           {
             TreeNode* lf=NULL;
             a->left=lf;
           }
          
           getline(s,str,',');
           if(str!="N")
           {
            
             TreeNode* r=new TreeNode(stoi(str));
             a->right=r;
             q.push(r);
           }
           else
           {
             TreeNode* r=NULL;
             a->right=r;
           }
          

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));