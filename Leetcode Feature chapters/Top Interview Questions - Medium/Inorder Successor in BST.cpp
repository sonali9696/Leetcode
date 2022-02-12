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
private:
    int found = 0;
    TreeNode* successor;
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        successor = NULL;
        inorderTraverse(root, p);
        return successor;
    }
    
    void inorderTraverse(TreeNode* root, TreeNode* p)
    {
        if(root->left) inorderTraverse(root->left, p);
        
        if(root == p) found = 1;
        
        if(successor == NULL && found == 1 && root != p) 
        //found = 1 for all elements at or after p so we want just after p
        {
            successor = root;
            return;
        }
        
        if(root->right) inorderTraverse(root->right, p);
    }
};