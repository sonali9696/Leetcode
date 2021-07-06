class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int, int> freq;
        
        for(int i=0; i<n; i++)
        {
            if(freq.find(arr[i]) == freq.end()) freq[arr[i]] = 1;
            else freq[arr[i]]++;
        }
        
        vector<int> frequencies; //each freq represents an element, we don't need to store what is the value of the element
        map<int, int>::iterator it;
        for(it = freq.begin(); it != freq.end(); it++)
        {
            frequencies.push_back(it->second);
        }
        
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        int n2 = frequencies.size(), ans = 0, currFreqCount = 0;
        for(int i=0; i<n2; i++)
        {
            currFreqCount += frequencies[i];
            ans += 1;
            if(currFreqCount >= (n/2)) break;
        }
        
        return ans;
        
        /*map<int,vector<int>> sortedByFreq; //(freq,values)
        map<int, int>::iterator it;
        for(it = freq.begin(); it != freq.end(); it++)
        {
            int val = it->first, freqOfVal = it->second;
            if(sortedByFreq.find(freqOfVal) == sortedByFreq.end()) sortedByFreq[freqOfVal] = {val};
            else sortedByFreq[freqOfVal].push_back(val);
        }
        
        map<int, vector<int>>::iterator it2;
        it2 = sortedByFreq.end();
        it2--;
        
        int count = 0, numElements = 0;
        while(count < n/2)
        {
            vector<int> v = it2->second;
            int n2 = v.size();
            for(int i=0; i<n2; i++)
            {
                count += it2->first;
                numElements++;
                if(count >= n/2) break;
            }
            if(it2 == sortedByFreq.begin()) break;
            it2--;
        }
        
        return numElements;*/
    }
};