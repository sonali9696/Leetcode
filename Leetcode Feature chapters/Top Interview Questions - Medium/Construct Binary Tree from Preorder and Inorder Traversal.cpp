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
    int preIndex;
    map<int, int> m;
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //value to index mapping in inorder to quickly find the preorder root in inorder
        for(int i=0; i<inorder.size(); i++) m[inorder[i]] = i;
        
        preIndex = 0; //index of root in preorder for current subtree
        
        return arrayToTree(preorder, 0, preorder.size()-1); 
    }
    
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right)
    {
        if(left > right) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        int indexOfRootInInorder = m[root->val];
        
        root->left = arrayToTree(preorder, left, indexOfRootInInorder-1);
        root->right = arrayToTree(preorder, indexOfRootInInorder+1, right);
        
        return root;
    }
    
    
};

/*class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        
        int rootNode = preorder[0];
        TreeNode* root = new TreeNode(rootNode);
        
        //search root in inorder to get left and right subtree
        //cant use binary search as no guarantee of sorting since it is not a binary SEARCH tree
        int index;
        vector<int> leftInorder, rightInorder;
        for(int i=0; i<inorder.size(); i++)
        {
            if(inorder[i] == rootNode) 
            {
                index = i;
                break;
            }
            leftInorder.push_back(inorder[i]);
        }
        
        for(int i=index+1; i<inorder.size(); i++) rightInorder.push_back(inorder[i]);
        
        //create leftpreorder whose size will be equal to size of leftInorder
        int size = leftInorder.size(); 
        vector<int> leftPreorder, rightPreorder;
        
        
        for(int i=1; i <= size; i++) leftPreorder.push_back(preorder[i]);
        for(int i=size+1; i < preorder.size(); i++) rightPreorder.push_back(preorder[i]);
        
        //link left, right subtree
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        
        return root;
    }
};*/