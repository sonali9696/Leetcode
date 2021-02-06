class Solution {
private:
	int ans;
public:
	void calcLongestConsecutive(TreeNode* root, TreeNode* parent, int count)
	{
        if(root == NULL) return;
        
        if(parent != NULL && root->val == parent->val + 1) count++;
        else count = 1;
        
        if(count > ans) ans = count;
        
		calcLongestConsecutive(root->left, root, count);
        calcLongestConsecutive(root->right, root, count);
	}
    
    int longestConsecutive(TreeNode* root) {
       	if(root == NULL) return 0;
		ans = 0;
        calcLongestConsecutive(root, NULL, 1);
		return ans;
    }
};


/*class Solution {
private:
	int ans;
public:
	void calcLongestConsecutive(TreeNode* root,int count)
	{
		count++; //counting current root
		if(root->left != NULL && root->left->val == root->val + 1) 
            calcLongestConsecutive(root->left, count);
		else if(root->right != NULL && root->right->val == root->val + 1) 
            calcLongestConsecutive(root->right, count);
		else if(count > ans) ans = count;
	}

    void preorder(TreeNode* root){
        if(root != NULL) {
            calcLongestConsecutive(root,0);
            preorder(root->left);
            preorder(root->right);
        }
    }
    
    int longestConsecutive(TreeNode* root) {
       	if(root == NULL) return 0;
		ans = 0;
        preorder(root); 
		return ans;
    }
};*/