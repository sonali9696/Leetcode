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
	map<string, int> subtreesCount; //subtrees - string, count

public:    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        serialize(root, ans);      
        return ans; 	
    }
	
    string serialize(TreeNode* node, vector<TreeNode*>& ans){
		if(node == NULL) return "#";
		string serializedString = to_string(node->val) + ',' + serialize(node->left, ans) + ',' + serialize(node->right, ans);
        if(subtreesCount.find(serializedString) == subtreesCount.end())
            subtreesCount[serializedString] = 1;
        else{
            subtreesCount[serializedString]++;
            if(subtreesCount[serializedString] == 2){
                ans.push_back(node);
            }
        }
        
        return serializedString;
    }
};

