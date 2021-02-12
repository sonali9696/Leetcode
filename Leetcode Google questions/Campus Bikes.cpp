class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        //0<=distance<=2000 as 0<=x,y<=1000
        //number of pairs is 10^6 >> 2000 so bucket sort used
        //i.e. array of distance mapped to all pairs of worker,bike having that distance
        vector<vector<pair<int,int> > > buckets(2001);

        /***Create buckets such that workers are sorted and for same worker, bikes are sorted-***/
        int n = workers.size(), m = bikes.size();
        
        //worker is in outside loop to maintain order 
        //such that for same distance lesser worker index is pushed first, 
        //and if same w index then lesser bike index pushed first
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int dist = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                buckets[dist].push_back(make_pair(i,j));
            }
        }

        /***assign bikes to workers-***/
        vector<int> workerToBike(n,-1); //answer is initially -1 i.e. unassigned
        vector<bool> isBikeUsed(m,false);

        //instead of iterating over each worker and trying to find that in which buckets does the worker exist and all -> tedious process
        //iterate each bucket and keep assigning workers and bikes by going to each pair and assigning
        //as it is already sorted in the desired way
        for(int k=0; k<2001; k++)
        {
            vector<pair<int,int> > temp = buckets[k];
            int l = temp.size();
            for(int i=0; i<l; i++)
            {
                pair<int,int> workerBike = temp[i];
                int w = workerBike.first, b = workerBike.second;
                if(workerToBike[w] == -1 && isBikeUsed[b] == false)
                {
                    workerToBike[w] = b;
                    isBikeUsed[b] = true;
                } 
            }
        }

        return workerToBike;
    }
};

