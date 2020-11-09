/*Good test cases - 
[[1,3],[6,9]]
[2,5]

[[1,2],[3,5],[6,7],[8,10],[12,16]]
[4,8]

[]
[5,7]

[[1,5]]
[2,3]

[[1,5]]
[2,7]

[[1,5],[7,8]]
[6,7]

[[1,5]]
[6,7]

[[1,5]]
[0,3]

[[2,6],[7,9]]
[15,18]*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> updatedInterval;
        int index = 0, n = intervals.size();
        if(n == 0) 
        {
            updatedInterval.push_back(newInterval);
            return updatedInterval;
        }
        
        while(index < n && intervals[index][0] <= newInterval[0]) 
        {
            updatedInterval.push_back(intervals[index]);
            //cout<<"pushed "<<intervals[index][0]<<" "<<intervals[index][1]<<endl;
            index++;
        }
        
        int last = updatedInterval.size() - 1;
        if(index == 0) updatedInterval.push_back(newInterval); //starts with this
        else //merge new interval with the last added interval
        {
            index--;
            if(updatedInterval[last][1] >= newInterval[0])
            {
                updatedInterval[last][1] = max(updatedInterval[last][1], newInterval[1]);
                index++;
            }
            else
            {
                updatedInterval.push_back(newInterval);
            }
        }
        last = updatedInterval.size() - 1; //for index = 0 case
        
        while(index < n  && updatedInterval[last][1] >= intervals[index][0]) //merge rest
        {
            updatedInterval[last][1] = max(updatedInterval[last][1], intervals[index][1]);
            //cout<<"changed "<<updatedInterval[last][0]<<" "<<updatedInterval[last][1]<<endl;
            index++;
        }
        
        while(index < n)
        {
            updatedInterval.push_back(intervals[index]);
            //cout<<"3 pushed "<<intervals[index][0]<<" "<<intervals[index][1]<<endl;
            index++;
        }
        
        return updatedInterval;
    }
};

/* TODO: below is more memory efficient as it is in place and uses binary search but it is failing for large inputs
//if anyone is able to find the issue in the bug, please feel free to fix it and raise merge request or mention it in issues tab of github or as comment in leetcode (https://leetcode.com/problems/insert-interval/discuss/929604/C%2B%2B-in-place-binary-search-solution-Need-help-TLE-for-large-inputs) or email me at sonali9696@gmail.com.

class Solution {
public:
    void merge(int pos, vector<vector<int>>& intervals)
    {
        //cout<<"pos="<<pos<<endl;
        int index = pos+1;
        while(index < intervals.size() && intervals[index][0] <= intervals[pos][1])
        {
            //cout<<"index="<<index<<endl;
            //cout<<intervals[index][0]<<" "<<intervals[index][1]<<endl;
            intervals[pos][1] = max(intervals[pos][1], intervals[index][1]);
            intervals.erase(intervals.begin()+index);
        }
    }
    
    void insertTarget(vector<vector<int>>& intervals,int low,int high,vector<int>& target, int n)
    {
        //cout<<"low="<<low<<",high="<<high<<endl;
        if(low > high) return;
        
        int mid = low + (high-low)/2;
        //cout<<"mid="<<mid<<endl;
        //cout<<intervals[mid][0]<<" "<<intervals[mid][1]<<endl;
        
        if(mid != n-1)
        {
            if(target[0] >= intervals[mid][0] && target[0] <= intervals[mid+1][0])
            {
                if(target[0] <= intervals[mid][1]) //merge
                {
                    //cout<<1<<endl;
                    intervals[mid][1] = max(intervals[mid][1], target[1]);
                    merge(mid, intervals);
                }
                else //insert here
                {
                    //cout<<2<<endl;
                    auto it = intervals.insert(intervals.begin()+mid+1, target);
                    merge(mid+1, intervals);
                }
            }
            else if(target[0] > intervals[mid+1][0])
            {
                //cout<<3<<endl;
                low = mid+1;
                insertTarget(intervals,low,high,target, n);
            }
            else if(target[0] < intervals[mid][0])
            {
                //cout<<4<<endl;
                high = mid;
                if(mid == 0) //insert at beginning
                {
                    auto it = intervals.insert(intervals.begin(), target);
                    merge(0, intervals);
                }
                else insertTarget(intervals,low,high,target, n);
            }
        }
        else
        {
            if(target[0] < intervals[mid][0])
            {
                //cout<<5<<endl;
                if(mid == 0)
                {
                    auto it = intervals.insert(intervals.begin(), target);
                    merge(0, intervals);
                }
                else
                {
                    high = mid;
                    insertTarget(intervals,low,high,target, n); 
                }
                
            }
            else if(target[0] <= intervals[mid][1])
            {
                //cout<<6<<endl;
                intervals[mid][1] = max(intervals[mid][1], target[1]);
                merge(mid, intervals);
            }
            else
            {
                //cout<<7<<endl;
                intervals.push_back(target);
            }
        }
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) intervals.push_back(newInterval);
        else insertTarget(intervals,0,n-1, newInterval,n);
        return intervals;
    }
};*/