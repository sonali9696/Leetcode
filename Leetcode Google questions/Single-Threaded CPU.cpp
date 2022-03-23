class Solution {
public:
    struct sortByFastestTask{
        bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
        {
            if(p1.first == p2.first)
                return p1.second > p2.second; //smaller index comes first
            
            return p1.first > p2.first; //smaller processing time comes first
        }
    };
    
    static bool sortTasks(const vector<int> &a, const vector<int> &b)
    {
        if(a[0] == b[0]) //same enqueue time
        {
            if(a[1] == b[1]) //same processing time
            {
                return a[2] < b[2]; //smaller index comes first
            }
            return a[1] < b[1]; //smaller processing time comes first
        }
        
        return a[0] < b[0]; //smaller enqueue time comes first
    }
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        //sort tasks by enqueue time but need to know index
        //if same enqueue time, then by processing time, else by index
        int n = tasks.size();
        for(int i=0; i<n; i++)
        {
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end(), sortTasks);
        
        //add available tasks to a min heap
        //sort min heap by processing time
        //if same processing time then shorter index
        //pick from this heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, sortByFastestTask> pq;
        
        long long int currentTime = 0;
        
        //0th task processed first
        currentTime += tasks[0][0] + tasks[0][1]; //enqueue + processing time
        
        vector<int> orderOfTasks;
        orderOfTasks.push_back(tasks[0][2]);
        
        //process all tasks
        for(int i=1; i<n; i++)
        {
            //add available tasks to heap
            if(tasks[i][0] <= currentTime) //enqueue time <= currentTime
            {
                pq.push(make_pair(tasks[i][1], tasks[i][2])); //processing time, index
            }
            else
            {
                if(pq.empty())
                {
                    //process next task in vector
                    currentTime = tasks[i][0] + tasks[i][1];
                    //computer may be idle until this gets enqueued
                    //hence reset time as the time to enqueue + process
                    
                    orderOfTasks.push_back(tasks[i][2]); //index
                }
                else
                {
                    //pop next available task to process
                    pair<int, int> nextTask = pq.top();
                    pq.pop();

                    currentTime += nextTask.first;
                    orderOfTasks.push_back(nextTask.second);
                    
                    --i;
                    //current task was not <= currentTime so it was not pushed
                    //however after processing tasks, time has changed so need to check again if now we should push it
                } 
            }
            
        }
        
        while(!pq.empty())
        {
            //pop next available task to process
            pair<int, int> nextTask = pq.top();
            pq.pop();

            currentTime += nextTask.first;
            orderOfTasks.push_back(nextTask.second);
        }
        
        
        return orderOfTasks;
    }
};