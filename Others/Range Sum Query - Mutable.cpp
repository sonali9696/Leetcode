//segment tree
class NumArray {
private:
    int n;
    vector<int> tree;
        
    void buildTree(vector<int>& nums) {
        //leaf nodes is number itself
        for (int i = n, j = 0;  i < 2 * n; i++,  j++)
            tree[i] = nums[j];
        
        //parent node is sum of child nodes
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    
    
public:
    NumArray(vector<int>& nums) {
        if (nums.size() > 0) {
            n = nums.size();
            for(int i=0; i<n * 2; i++) tree.push_back(0);
            buildTree(nums);
        }
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val; //updating corresponding leaf node
        
        while(index > 0)
        {
            int left = index;
            int right = index;
            
            //find whether this leaf is right child or left child
            if(index % 2 == 0) right = index+1;
            else left = index-1;
            
            //parent is updated after child is updated
            tree[index/2] = tree[left] + tree[right];
            index /= 2;
        }   
    }
    
    int sumRange(int left, int right) {
        //get their leaf nodes
        left += n;
        right += n;
        
        int sum = 0;
        while(left <= right)
        {
            if(left % 2 == 1) //right child means parent contains sum of left + another child which is outside [left,right] so don't need parent sum
            {
                sum += tree[left]; //[l, some range] added
                left++;
            }
            
            if(right % 2 == 0) //left child
            {
                sum += tree[right]; //parent contains r and another child outside [l,r] so we don't need parent sum
                right--;
            }
            
            left /= 2;
            right /= 2;
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */