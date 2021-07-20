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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Value of current node or parent node.
        int parentVal = root->val;
        int pVal = p->val; 
        int qVal = q->val;

        if (pVal > parentVal && qVal > parentVal) {
            // If both p and q are greater than parent then both are in right subtree and current node cant be LCS
            return lowestCommonAncestor(root->right, p, q);
        } else if (pVal < parentVal && qVal < parentVal) {
            // If both p and q are lesser than parent then both are in left subtree and current node cant be LCS
            return lowestCommonAncestor(root->left, p, q);
        } else {
            // We have found the split point, i.e. the LCA node.
            return root;
        }
    }
};