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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> to_delete_set;
        for(int v : to_delete) to_delete_set.insert(v);
		vector<TreeNode*> result;
		helper(root, result, to_delete_set, true);
		return result;
    }

	TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool isRoot){
		if(node == NULL) return NULL; //cant check left/right of NULL
		
		bool isDeleted = (to_delete_set.find(node->val) != to_delete_set.end());
		
		if(isRoot == true && isDeleted == false) result.push_back(node);
	
		node->left = helper(node->left, result, to_delete_set, isDeleted);
		node->right = helper(node->right, result, to_delete_set, isDeleted);

		if(isDeleted == true) return NULL;
		else return node;
    }
};