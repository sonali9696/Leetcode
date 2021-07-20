class Solution {
private:
    vector<int> original;
    vector<int> array;
public:
    Solution(vector<int>& nums) {
        original = nums;
        array = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = array.size();
        
        //pick any random element from starting till end-i
        //swap current element with that
        //current element is moving from right to left
        //note that we can swap with itself to include all permutation
        
        for(int i=0; i<n; i++)
        {
            int new_choice = rand() % (n - i); //generating an integer within the range of [0, n-i-1]
            swap(array[n-1-i], array[new_choice]);
        }
        
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */