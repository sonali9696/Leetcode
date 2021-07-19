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
        // if root is null, return  
        if(!root) return nullptr;
        
        // case1: test if root equals p or q
        if(root == p || root == q ) return root;
        
        // case2 & 3: try to find LCA in left/right subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // if left is not null, case1 is fulfilled in next recursion, which means p or q exactly exists in left subtree
        // if both left and right are not null, p and q exists in left/right subtree separatedly,
        // so root is the LCA.
        if(left && right ) return root;
        
        
        // if only left is not null, p/q both exist in left subtree. so return left.
        // the same for the right subtree case.
        return left?left:right;
        
    }
};