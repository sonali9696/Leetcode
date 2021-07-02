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
    vector<vector<int>> ans;
public:
    int getHeight(TreeNode* node){
        if(node == NULL) return -1;
        
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        int height = max(leftHeight, rightHeight) + 1;
        
        if(ans.size() == height) ans.push_back({});
        ans[height].push_back(node->val);
        
        return height;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);
        
        return ans;
    }
};Find Leaves of Binary Tree