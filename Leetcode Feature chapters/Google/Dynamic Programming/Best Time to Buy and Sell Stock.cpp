class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size(), left = 1, right = n-2;
	    if(n == 0) return 0;
        int leftmin = prices[0], rightmax = prices[n-1];
        int leftProfit = 0, rightProfit=0;
        
        while(left < n && right >=0)
        {
            if(prices[left] < leftmin) leftmin = prices[left];
            if(prices[left] - leftmin > leftProfit) leftProfit = prices[left] - leftmin;

            if(prices[right] > rightmax) rightmax = prices[right];
            if(rightmax - prices[right] > rightProfit) rightProfit = rightmax - prices[right];

            int currMaxProfit = max(leftProfit, rightProfit);
            if(profit < currMaxProfit) profit = currMaxProfit;

            left++;
            right--;
        }
        
        return profit;
    }
};

