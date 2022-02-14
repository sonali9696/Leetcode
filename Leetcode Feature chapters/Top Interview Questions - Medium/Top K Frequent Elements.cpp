class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freqMap;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(freqMap.find(nums[i]) == freqMap.end()) freqMap[nums[i]] = 0;
            
            freqMap[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> kFreq; //min heap
        
        map<int,int>::iterator it;
        for(it = freqMap.begin(); it != freqMap.end(); ++it)
        {
            kFreq.push(make_pair(it->second, it->first)); //to sort heap as per freq
            
            if(kFreq.size() > k) kFreq.pop();//min heap of size k to store k most freq elements
        }
        
        vector<int> ans;
        while(!kFreq.empty())
        {
            pair<int,int> p = kFreq.top();
            ans.push_back(p.second);
            kFreq.pop();
        }
        
        return ans;
    }
};