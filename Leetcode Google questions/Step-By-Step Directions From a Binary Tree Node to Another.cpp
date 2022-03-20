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

//first we get the paths of all nodes from root in L/R format
//there is one root of a subtree whose left is s/t and right is the other
//this root can be called LCA (lowest common ancestor)
//to find path of s & t from LCA, delete the common prefix of the path from main root
//now source to LCA will be changed to UU. 
//i.e. if LCA -> s is LL. Now s->LCA is UU
//LCA->t is as is so append both to get ans

class Solution {
public:
    TreeNode* lca(TreeNode* root, int v1, int v2)
    {
        if(!root)
            return NULL;
        
        if(root->val==v1 or root->val==v2)
            return root;
        
        TreeNode* l=lca(root->left,v1,v2);
        TreeNode* r=lca(root->right,v1,v2);
        
        if(l and r)
            return root;
        if(l)
            return l;
        else
            return r;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* r=lca(root,startValue,destValue);
        
        string s1,s2;
        dfs(r,startValue,s1);
        dfs(r,destValue,s2);
        
        reverse(s2.begin(),s2.end());
        
        for(auto &i: s1)
            i='U';
        return s1+s2;
    }
    bool dfs(TreeNode* root, int x,string &s)
    {
        if(!root)
            return false;
        
        if(root->val==x)
            return true;
        
        bool l=dfs(root->left,x,s);
        bool r=dfs(root->right,x,s);
      
        if(l)
        {
            s+='L';
            return true;
        }
        else
            if(r)
        {
             s+='R';
            return true;
        }
        
        return false;
    }
};

/*class Solution {
private:
    
    bool traverse(TreeNode* root, int nodeVal, string& path)
    {
        if(root == NULL) return false;
        
        if(root->val == nodeVal) return true;
            
        bool l = traverse(root->left, nodeVal, path);
        bool r = traverse(root->right, nodeVal, path);
        
        if(!l && !r) return false;
        
        if(l) path += 'L';
        if(r) path += 'R';
        return true;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        //get path from root
        string rootToS = "", rootToT = "";
        traverse(root, startValue, rootToS);
        traverse(root, destValue, rootToT);
        
        reverse(rootToS.begin(), rootToS.end());
        reverse(rootToT.begin(), rootToT.end());
        
        //remove common prefix
        int i=0;
        while(i < rootToS.length() && i < rootToT.length()
              && rootToS[i] == rootToT[i])
        {
            i++;
        }
        rootToS = rootToS.substr(i);
        rootToT = rootToT.substr(i);
        
        //form answer
        string ans = "";
        for(int i=0; i<rootToS.length(); i++) ans.push_back('U');
        ans += rootToT;
        
        return ans;
    }
};*/

//MLE - The fix is to build the matching path from the bottom up after finding a match. If you generate the path as you traverse down the binary tree, you end up wasting memory allocations for paths that don't end up being relevant to the answer.

/*class Solution {
private:
    string rootToS, rootToT;
    
    void traverse(TreeNode* root, int startVal, int destVal, string temp)
    {
        if(root == NULL) return;
        
        if(root->val == startVal) rootToS = temp;
        else if(root->val == destVal) rootToT = temp;
            
        traverse(root->left, startVal, destVal, temp + "L");
        if(rootToS != "" && rootToT != "") return;
        
        traverse(root->right, startVal, destVal, temp + "R");
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        traverse(root, startValue, destValue, "");
        
        int i=0;
        while(i < rootToS.length() && i < rootToT.length()
              && rootToS[i] == rootToT[i])
        {
            i++;
        }
        
        rootToS = rootToS.substr(i);
        rootToT = rootToT.substr(i);
        
        string ans = "";
        for(int i=0; i<rootToS.length(); i++) ans.push_back('U');
        ans += rootToT;
        
        return ans;
    }
};*/