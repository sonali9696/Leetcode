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
       	if(root == NULL) return "";
		queue<TreeNode*> q;
        q.push(root);
        
        string s = "";
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            
            if(p == NULL) s += "null ";
            else s += to_string(p->val) + " ";

            if(p != NULL)
            {
                q.push(p->left);
                q.push(p->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		if(data.length() == 0) return NULL; //empty tree
        
        stringstream str(data);
        string node;
        str >> node; //gives words separated by space, one by one
        
        //create tree
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(node)); //root can't be null, empty tree handled already
        q.push(root);
        
        while(str >> node)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(node.compare("null") == 0) curr->left = NULL;
            else
            {
                curr->left = new TreeNode(stoi(node)); 
                q.push(curr->left);
            }
            
            str >> node;
            
            if(node.compare("null") == 0) curr->right = NULL;
            else
            {
                curr->right = new TreeNode(stoi(node)); 
                q.push(curr->right);
            }
        }
        
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

