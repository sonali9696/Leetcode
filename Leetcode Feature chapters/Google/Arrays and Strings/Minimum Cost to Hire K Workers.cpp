class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    
        double minCost = DBL_MAX;
        int n = quality.size();

        vector<pair<double,double>> ratio_quantity;

        for(int i=0; i<n; i++)
            ratio_quantity.push_back(make_pair((double)wage[i]/(double)quality[i],(double)quality[i]));
        
        sort(ratio_quantity.begin(), ratio_quantity.end());
        //first K workers to be picked up with ratio of captain = ratio of Kth worker added to heap
        
        double totalQuality = 0;
        priority_queue<double> pq; //max heap to remove max to replace by a smaller value
        
        for(int i=0; i<n; i++)
        {
            totalQuality += ratio_quantity[i].second;
            
            pq.push(ratio_quantity[i].second);
            
            if(pq.size() > K)
            {
                totalQuality -= pq.top();
                pq.pop(); //top is removed
            }
            
            if(pq.size() == K)
            {
                double currentCost = totalQuality*ratio_quantity[i].first;
                if(currentCost < minCost) minCost = currentCost;
            }
        }
        
        return minCost;

    }

};