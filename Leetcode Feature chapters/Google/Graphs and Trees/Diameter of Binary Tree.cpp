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

//good test case -
//[1,2,3,4,5,null,null,3,null,6,null,null,5,null,7,null,null,null,8]

class Solution {
private:
    int diameter = 0;
    
public:
    int countDiameter(TreeNode* root)
    {
        if(root == NULL) return -1;
        if(root->left == NULL && root->right == NULL) return 0;

        int l = countDiameter(root->left);
        int r = countDiameter(root->right);

        int diameterThroughCurrentNode = l + r + 2; 
        //2 edges as 1 edge connects l and root, 1 connects r and root
        if(diameterThroughCurrentNode > diameter)
            diameter = diameterThroughCurrentNode;
        
        return max(l,r)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = countDiameter(root);
        if(diameter < ans) diameter = ans;
        
        return diameter;
    }
};

