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
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL && root2 == NULL) return true; //both null
        else if(root1 == NULL || root2 == NULL) return false; //only 1 is null
        else if(root1->val != root2->val) return false;
         
        bool sameChildren = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool flippedChildren = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        if(sameChildren || flippedChildren) return true;
        else return false;      
    }
};

