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
private:
    int index;
    int n;
    
public:
    TreeNode* helper(int lowerLimit, int upperLimit, vector<int>& preorder)
    {
        if(index == n) return NULL; //tree constructed
        
        int val = preorder[index];
        //if current element couldn't be placed to meet BST req
        if(val < lowerLimit || val > upperLimit) return NULL;
        
        //else place current element here
        index++;
        TreeNode* root = new TreeNode(val);
        root->left = helper(lowerLimit,val, preorder);
        root->right = helper(val, upperLimit, preorder);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        index = 0; //index at preorder array
        
        return helper(INT_MIN, INT_MAX, preorder);
    }
};