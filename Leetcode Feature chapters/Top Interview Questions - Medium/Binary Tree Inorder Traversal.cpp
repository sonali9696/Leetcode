/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Iterative approach-
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> s;
        TreeNode* ptr = root;
        while(ptr != NULL || !s.empty())
        {
            while(ptr != NULL)
            {
                s.push(ptr);
                ptr = ptr->left;
            }
            
            ptr = s.top();
            ans.push_back(ptr->val);
            s.pop();
            ptr = ptr->right;
        }
        
        return ans;
    }
};

/*class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;
        else
        {
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
        
    }
};*/