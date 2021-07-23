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
class Solution {
public:
    bool removeNonOneSubtrees(TreeNode* root){
        if(root == NULL) return false;
        
        bool leftCheck = removeNonOneSubtrees(root->left);
        bool rightCheck = removeNonOneSubtrees(root->right);
        
        if(leftCheck == false) root->left = NULL;
        if(rightCheck == false) root->right = NULL;
        
        if(leftCheck == true || rightCheck == true) return true;
        else if(root->val == 1) return true;
        else return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool hasOne = removeNonOneSubtrees(root);
        if(hasOne == false) return NULL;
        else return root;
    }
};