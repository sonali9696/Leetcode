class Solution {
private:
vector<int> result;
public:
	int calcCoinsNeeded(vector<int>& coins, int amount)
	{
		if(amount == 0) return 0;
		if(result[amount] != -2) return result[amount];

        int n = coins.size();
        int min = INT_MAX, currResult;
        for(int i=0; i<n; i++)
        {
            if(coins[i] > amount) continue;
            else 
            {
                int currCoins = calcCoinsNeeded(coins,amount-coins[i]);
                if(currCoins == -1) currResult = -1;
                else currResult = 1 + currCoins;
                if(currResult != -1 && currResult < min) min = currResult;
            } 
            
        } 
        if(min != INT_MAX) result[amount] = min;
        else result[amount] = -1;
        return result[amount];
	}

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        for(int i=0; i<amount+1; i++) result.push_back(-2);
        result[0] = 0;
        return calcCoinsNeeded(coins,amount);
    }
};

