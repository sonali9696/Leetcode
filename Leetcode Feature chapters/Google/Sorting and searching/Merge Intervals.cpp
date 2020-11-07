class Solution {
public:
	static bool sortInterval(const vector<int> &a, const vector<int> &b)
	{
		if(a[0] == b[0]) return a[1] < b[1]; //don't write <= as that gives runtime error in c++
        //because in c++, your comparison function should satisfy weak strict ordering. Using <= is undefined behavior. You can read more about it here: https://stackoverflow.com/questions/979759/operator-and-strict-weak-ordering
		else return a[0] < b[0];
	}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); //size before merge
        vector<vector<int>> mergedInterval;
        if(n == 0 || (n == 1 && intervals[0].size() == 0)) return mergedInterval;
        
        sort(intervals.begin(), intervals.end(), sortInterval);
        
        mergedInterval.push_back(intervals[0]); //0th index pushed in case n=1  
        int index = 0;
        for(int i=1; i < n; i++) 
        {
            //overlap - begin is same. end updated
            if(intervals[i][0] <= mergedInterval[index][1]) 
                mergedInterval[index][1] = max(mergedInterval[index][1],intervals[i][1]);
            else 
            {
                mergedInterval.push_back(intervals[i]);
                index++;
            }
        }

        return mergedInterval;
    }
};

