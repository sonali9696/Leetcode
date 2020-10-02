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


//good test cases:
//all negative: [-1, -2, -3], [-5,-2,-3]
//[5,-2,-3]
//taking only subtree without root - [-5,null,3,-2,1]

class Solution {
public:
    
    int maxSum = INT_MIN;

    int sumOfPath(TreeNode* ptr)
	{
        if(ptr == NULL) return 0;
        
        //what if all nodes are negative??
        int sum1 = max(sumOfPath(ptr->left),0);
        int sum2 = max(sumOfPath(ptr->right),0);

        //if highest is by taking ptr as root
        //updates global variable;
        if(sum1+sum2+ptr->val > maxSum) maxSum = sum1+sum2+ptr->val;
        //above takes care of the case where all nodes are negative 
        //as sum1=0,sum2=0 for every leaf and every node with -ve left & right subtree
        //so sum = value of node itself
        
        //for recursion
        return ptr->val + max(sum1,sum2);
    }
	
    int maxPathSum(TreeNode* root) {
        sumOfPath(root);
	    return maxSum;
    }

};
