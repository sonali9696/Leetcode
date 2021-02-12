class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
		int n = bulbs.size();
		vector<int> dayItIsTurnedOn(n,-1);
		for(int i=0; i<n; i++) dayItIsTurnedOn[bulbs[i]-1] = i+1;
		//now day is 1 to n, bulbs are 0 to (n-1)
		
        int left = 0, right = k+1, ans = INT_MAX, i;
        while(right < n)
        {
            for(i=left+1; i<right; i++)
            {
                cout<<i<<endl;
                if(dayItIsTurnedOn[i] > dayItIsTurnedOn[left] && dayItIsTurnedOn[i] > dayItIsTurnedOn[right]) continue;
                else break;
            }
            if(i != right)
            {
                left = i; //it is not left++ simply, because dayItIsTurnedOn[i] is < days[left] or right. Since we are looking for a value which is lesser than the k elements between them, we don't choose the elements before this as we know that right will be lesser than them and hence will not result in a valid candidate anyway.
                right = i+k+1;
            }
            else //candidate ans found, store minimum ans
            {
                ans = min(ans,max(dayItIsTurnedOn[left],dayItIsTurnedOn[right]));
                left = right;
                right = left + k + 1;
            }
        }
        return (ans == INT_MAX)?-1:ans;
    }
};

/*class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        set<int> s;
        for(int i=0; i<n; i++)
        {
            s.insert(bulbs[i]);
            auto it = s.lower_bound(bulbs[i]);
            
            if(it != s.begin()) 
            {
                it--; 
                if((bulbs[i] - *it - 1) == k) return (i+1);
            }
            
            it = s.upper_bound(bulbs[i]);
            if(it != s.end())
            {
                if((*it - bulbs[i] - 1) == k) return (i+1);
            }
        }
        
        return -1;
    }
};*/