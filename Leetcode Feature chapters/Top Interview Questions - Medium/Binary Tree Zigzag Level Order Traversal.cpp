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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int> > ();
        }
        vector<vector<int> > result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while ( !nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
    
    /*vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> oddLevel, evenLevel;
        int level = 1;
        oddLevel.push(root);
        while(!oddLevel.empty() || !evenLevel.empty())
        {
            vector<int> curr;
            if(level % 2 != 0) //odd
            {
                while(!oddLevel.empty())
                {
                    TreeNode* currNode = oddLevel.top(); 
                    curr.push_back(currNode->val);
                    oddLevel.pop();
                    if(currNode->left != NULL) evenLevel.push(currNode->left);
                    if(currNode->right != NULL) evenLevel.push(currNode->right);    
                }
            }
            else
            {
                while(!evenLevel.empty())
                {
                    TreeNode* currNode = evenLevel.top(); 
                    curr.push_back(currNode->val);
                    evenLevel.pop();
                    if(currNode->right != NULL) oddLevel.push(currNode->right);
                    if(currNode->left != NULL) oddLevel.push(currNode->left);    
                }
            }
            
            level++;
            if(curr.size() != 0) ans.push_back(curr);
        }
        
        return ans; 
    }*/
};