class Solution {
public:
    
    //O(n logn):
    /*int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1]; //starts with 0
    }*/
    
    //min heap of k elements
    //O(nlogk) - creates heap, //space: O(k) 
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
            //NOTE: DON'T POP THEN PUSH, PUSH THEN POP
            //WHY? TRY WITH [3,2,1] IN BOTH WAY
        }
        
        return pq.top();
    }
    
    //max heap of n elements, then popping k-1 times
    //O(n log n) - worst case, or, O(n) - tight bound.
    //O(n + klogn) -> k-1 times heapify which takes log(n)
    //space complexity: O(n)
    /*int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        
        for(int i=0; i<n; i++) pq.push(nums[i]);
        
        for(int i=1; i<=k-1; i++) pq.pop();
        
        return pq.top();
    }*/
    
};