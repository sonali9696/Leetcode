class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        //extract hour and min
        //store it in minutes format i.e. H*60 + M
        
        vector<int> mins;
        for(string time: timePoints)
        {
            int H = stoi(time.substr(0,2));
            int M = stoi(time.substr(3, 2));
            
            int t = 60*H + M;
            mins.push_back(t);
            
            if(t < 720) //if it is less than 12 noon then it could be closest
            //while comparing with time of prev day i.e. 23:59 and 00:00
            //or with current day i.e. 00:00 and 01:01
            //so have to consider both as current day or next day
            {
                mins.push_back(24*60 + t); //adding 24 hours is next day
                //so 00:00 becomes 24:00
            }    
        }
        
        
        sort(mins.begin(), mins.end());

        int closestTime = INT_MAX;
        for(int i=0; i<mins.size()-1; i++)
        {
            closestTime = min(closestTime, mins[i+1] - mins[i]);
        }

        return closestTime;
        
    }
};