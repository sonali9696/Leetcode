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
    bool checkChildren(TreeNode* root1, TreeNode* root2)
    {
        bool leftFlip = flipEquiv(root1->left, root2->left);
        bool rightFlip = flipEquiv(root1->right, root2->right);
        if(leftFlip == false || rightFlip == false) return false;
        else return true;
    }
    
    TreeNode* flipChildren(TreeNode* root1)
    {
        TreeNode* temp = root1->left;
        root1->left = root1->right;
        root1->right = temp;
        return root1;
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL && root2 == NULL) return true;
        else if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL)) return false;
        if(root1->val != root2->val) return false;

        if(root1->left == NULL && root1->right == NULL)
        {
            if(root2->left == NULL && root2->right == NULL) return true;
            else return false;
        }
        else if(root2->left == NULL && root2->right == NULL)
        {
            if(root1->left == NULL && root1->right == NULL) return true;
            else return false;
        }
        else if(root1->left == NULL && root1->right != NULL)
        {
            if(root2->left == NULL && root2->right != NULL) 
            {
                if(root2->right->val == root1->right->val) return checkChildren(root1,root2);
                else return false;
            }
            else if(root2->left != NULL && root2->right == NULL) 
            {
                if(root1->right->val == root2->left->val)
                {
                    root1 = flipChildren(root1);
                    return checkChildren(root1,root2);
                }
                else return false;
            }
            else return false;
        }
        else if(root1->left != NULL && root1->right == NULL)
        {
            if(root2->left != NULL && root2->right == NULL) 
            {
                if(root1->left->val == root2->left->val) return checkChildren(root1,root2);
                else return false;
            }
            else if(root2->left == NULL && root2->right != NULL) 
            {
                if(root2->right->val == root1->left->val)
                {
                    root1 = flipChildren(root1);
                    return checkChildren(root1,root2);
                }
                else return false;
            }
            else return false;
        }
        else if(root2->left == NULL && root2->right != NULL)
        {
            if(root1->left == NULL && root1->right != NULL) 
            {
                if(root2->right->val == root1->right->val) return checkChildren(root1,root2);
                else return false;
            }
            else if(root1->left != NULL && root1->right == NULL) 
            {
                if(root2->right->val == root1->left->val)
                {
                    root1 = flipChildren(root1);
                    return checkChildren(root1,root2);
                }
                else return false;
            }
            else return false;
        }
        else if(root2->left != NULL && root2->right == NULL)
        {
            if(root1->left != NULL && root1->right == NULL) 
            {
                if(root1->left->val == root2->left->val) return checkChildren(root1,root2);
                else return false;
            }
            else if(root1->left == NULL && root1->right != NULL) 
            {
                if(root1->right->val == root2->left->val)
                {
                    root1 = flipChildren(root1);
                    return checkChildren(root1,root2);
                }
                else return false;
            }
            else return false;
        }
        else if(root1->left->val == root2->right->val && root1->right->val == root2->left->val)
        {
            //flip it
            root1 = flipChildren(root1);
            return checkChildren(root1,root2);
        }
	    else if(root1->left->val == root2->left->val || root1->right->val == root2->right->val)
            return checkChildren(root1,root2);
        else return false;
    }
};

