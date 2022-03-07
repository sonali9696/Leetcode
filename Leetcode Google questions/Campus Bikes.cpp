class Solution {
public:
    // Function to return the Manhattan distance
    int distance(vector<int>& worker_loc, vector<int>& bike_loc) {
        return abs(worker_loc[0] - bike_loc[0]) + abs(worker_loc[1] - bike_loc[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // List of triplets (distance, worker, bike) for each bike corresponding to worker
        vector<vector<tuple<int, int, int>>> workerToBikeList;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;
        
        for (int worker = 0; worker < workers.size(); worker++) {
            // Add all the bikes with their distances from the current worker
            vector<tuple<int, int, int>> currWorkerPairs;
            for (int bike = 0; bike < bikes.size(); bike++) {
                int dist = distance(workers[worker], bikes[bike]);
                currWorkerPairs.push_back({dist, worker, bike});
            }
            
            // Sort the workerToBikeList for the current worker in reverse order.
            sort(currWorkerPairs.begin(), currWorkerPairs.end(), greater<tuple<int, int, int>>());

            // For each worker, add their closest bike to the priority queue
            pq.push(currWorkerPairs.back());
            // Second last bike is now the closest bike for this worker
            currWorkerPairs.pop_back();
            
            // Store the remaining options for the current worker in workerToBikeList
            workerToBikeList.push_back(currWorkerPairs);
        }
        
        // Initialize all values to false, to signify no bikes have been taken
        vector<int> bikeStatus(bikes.size(), false);
        // Initialize all index to -1, to signify no worker has a bike
        vector<int> workerStatus(workers.size(), -1);
        
        while (!pq.empty()) {
            // Pop the pair with smallest distance
            auto[dist, worker, bike] = pq.top();
            pq.pop();
            bike = bike;
            worker = worker;
            
            if (!bikeStatus[bike]) {
                // If the bike is free, assign the bike to the worker
                bikeStatus[bike] = true;
                workerStatus[worker] = bike;
            } else {
                // Otherwise, add the next closest bike for the current worker
                pq.push(workerToBikeList[worker].back());
                workerToBikeList[worker].pop_back();
            }
        }
        
        return workerStatus;       
    }
};

/*class Solution {
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
};*/

