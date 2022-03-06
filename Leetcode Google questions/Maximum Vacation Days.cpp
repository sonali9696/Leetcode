class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        //optimization - to calculate dp we just need values of next week
        //so can store in 1D array instead of 2D to save space
        
        if(days.size() == 0 || flights.size() == 0) return 0;
        
 		int n = days.size(), k = days[0].size();
        //n = number of cities, k = number of weeks
        
        int dp[n];//rows=num of cities
        memset(dp,0,sizeof(dp));
		
		//fill backwards from last week - finally dp[0][0] is answer
		for(int currWeek = k-1; currWeek >= 0; currWeek--)
		{
            int temp[n]; //to store values of current week temporarily
            //dp has values of next week
            
            memset(temp, 0, sizeof(temp));
            
			for(int currCity = 0; currCity < n; currCity++)
			{
				//if we stay in same city-
				temp[currCity] = days[currCity][currWeek]+dp[currCity]; 

				//if we change city this week
				for(int i=0; i<n; i++)
				{
					if(flights[currCity][i] == 1)
                    {
                        temp[currCity] = max(temp[currCity], days[i][currWeek] + dp[i]);
                    }                        
				}
			}
            
            //update dp array with current week values
            for(int i=0; i<n; i++) dp[i] = temp[i];
		}

		return dp[0];
		
    }
};

/*class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
 		int n = flights.size(), k = days[0].size();
        int dp[n][k+1];//rows=num of places, cols=num of weeks+1
		//last col is cushion for dp calc
		for(int i = 0; i<n; i++) dp[i][k] = 0;

		//fill backwards from last week - finally dp[0][0] is answer
		for(int currWeek = k-1; currWeek>= 0; currWeek--)
		{
			for(int currCity = 0; currCity < n; currCity++)
			{
				//if we stay in same city-
				dp[currCity][currWeek] = days[currCity][currWeek]+dp[currCity][currWeek+1]; 

				//if we change city this week
				for(int i=0; i<n; i++)
				{
					if(flights[currCity][i] == 1)
                        dp[currCity][currWeek] = max(dp[currCity][currWeek], days[i][currWeek] + dp[i][currWeek+1]);
				}
			}
		}

		return dp[0][0];
		
    }
};*/

/*class Solution {
public:
	int dfs(vector<vector<int>>& flights, vector<vector<int>>& days,vector<vector<int>>& mem, int currCity, int currWeek)
	{
		if(currWeek == days[0].size()) return 0;

		if(mem[currCity][currWeek] != -1) return mem[currCity][currWeek];

		int maxvac = 0;
		for(int i = 0; i < flights.size(); i++)
		{
			if(flights[currCity][i] == 1 || i == currCity)
			{
				int vac = days[i][currWeek] + dfs(flights,days,mem, i,currWeek+1);
				if(vac > maxvac) maxvac = vac;
			}
		}
		mem[currCity][currWeek] = maxvac;
		return maxvac;
	}

    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
       	vector<vector<int>> mem(flights.size()); //row=number of cities
		int cols = days[0].size();//col = number of weeks
		for(int i=0; i<mem.size(); i++) mem[i] = vector<int>(cols,-1); 

        return dfs(flights, days, mem, 0, 0); 
    }
};*/

