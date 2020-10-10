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

            int depth (TreeNode* root)
            {
                if(root == NULL) return 0;
                int depth = 0;

                TreeNode* ptr = root->left;
                while(ptr != NULL)
                {
                    depth++;
                    ptr = ptr->left;
                }
                
                return depth;
            }
	
            bool leafExists(int n, TreeNode* root, int d)
            {
                int l = 0, r= pow(2,d)-1;
                //root has range [l,r] under it

                int mid;

                TreeNode *ptr = root;
                int level = 0;

                while(level < d && l < r) //while not a leaf
                {
                    mid = (l+r)/2;
                    if(n > mid)
                    {
                        l = mid+1;
                        ptr = ptr->right;
                    }
                    else //includes n=mid
                    {
                        ptr = ptr->left;
                        r = mid;
                    }

                    if(ptr == NULL) return false;

                    level++;
                }

                if((level == d || l == r) && ptr != NULL) return true;
                else return false;
            }
	
            int countNodes(TreeNode* root) {
    		
                //all levels filled except last i.e. 
                //total = 2^0 + 2^1 + .. + 2^(d-1) + last level nodes
                // total = (2^d-1) + last level nodes --> starting d with 0 not 1 here
                //d starts with 1

                if(root == NULL) return 0; //empty tree
                int d = depth(root);
                if(d == 0) return 1; //0 depth means 1 node - just root
                //cout<<"depth:"<<d<<endl;

                int ans = pow(2,d)-1;

                //find nodes in last level
                //max nodes in last level is 2^d
                //numbering of leaves is 0 to 2^d-1

                int low = 0, high = pow(2,d)-1;
                int mid;
                while(low<=high)
                {
                    mid = (low+high)/2;
                    //cout<<"searching "<<mid<<endl;
                    bool found = leafExists(mid, root,d);
                    if(found == true) low = mid+1;
                    else high = mid-1;
                }

                ans += (low); //as low = high + 1 and low starts with 0 so low=3 means 0 to 2 exists so 3 nodes
                
                return ans;
            }

};


    /*void preorder(vector<int> &order, TreeNode* root)
    {
        if(root == NULL) return;

        order.push_back(root->val);
        preorder(order, root->left);
        preorder(order, root->right);
    }
	
    int countNodes(TreeNode* root) {
        vector<int> order;
        preorder(order, root); 
        return order.size();
    }
};*/

