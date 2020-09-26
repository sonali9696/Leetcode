class Solution {
public:
    static bool compareVec(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0]; //sort by start time
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compareVec);
            
        /*for(int i=0; i<intervals.size();i++)
        {
            for(int j=0; j<intervals[i].size();j++) cout<<intervals[i][j]<<" ";
            
            cout<<endl;
        }*/
        
        //vector<int> latestEndTimeInRooms;
        //int earliestEndTime, index;
        priority_queue<int,vector<int>,greater<int>> latestEndTimeInRooms_Heap;
        for(int i=0; i < intervals.size(); i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if(latestEndTimeInRooms_Heap.size() == 0)
            {
                latestEndTimeInRooms_Heap.push(end);
                //earliestEndTime = end;
                //index = 0;
            }
            else
            {
                if(latestEndTimeInRooms_Heap.top() <= start) //doesn't need new room
                    latestEndTimeInRooms_Heap.pop();
                 
                latestEndTimeInRooms_Heap.push(end); //new room or substitutes latest end time in existing room
                
            }
            
        }
        
        return latestEndTimeInRooms_Heap.size();
        
        
    }
};