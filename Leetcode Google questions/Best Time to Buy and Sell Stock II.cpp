class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxprofit = 0;
        int i = 0, valley = prices[0], peak = prices[1];
        while(i+1 < n)
        {
            while((i+1)<n && prices[i+1] <= prices[i]) i++;
            valley = prices[i];
            while((i+1)<n && prices[i+1] >= prices[i]) i++;
            peak = prices[i];
            maxprofit += (peak-valley);
        }
        
        return maxprofit;
    }
};