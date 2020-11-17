class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size(), i = 1;
	    if(n == 0) return 0;
        int currmin = prices[0];
        while(i < n)
        {
            if(prices[i] < currmin) currmin = prices[i];
            if(prices[i] - currmin > profit) profit = prices[i] - currmin;
            i++;
        }
        
        return profit;
    }
};

