class Solution {
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
};

