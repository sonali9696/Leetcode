//Topological sort - adding nodes of zero indegree to queue and processing them first
//supplies will initially have zero indegree

/*class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        queue<string> q;
		
		// this stores indegree of each recipes
        unordered_map<string,int> inorder;
		//stores all the relations of graph whre it's key will be some supply/recipe need for some recipe
        unordered_map<string,vector<string>> adj;
        vector<string> ans;
		
		//push every supply element in queue as it's indegree will be already zero
        for(string s: supplies) q.push(s);
        
		
        for(int i=0; i< recipes.size();i++){
            for(string str: ingredients[i]){
			//we are increasing indegree of each recipe according to no. of things needed for it
                inorder[recipes[i]]++;
			//we are pushing each recipe corresponding to ingredient 
                adj[str].push_back(recipes[i]);
            }
        }
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(string s: adj[curr]){
			
			//checking if indegree of recipe & pushing it in ans and que as it can be ingredient for some other recipe
                if(--inorder[s]==0){
                    ans.push_back(s);
                    q.push(s);
                }
            }
        }
        return ans;
    }
};*/


class Solution {
private:
    unordered_map<string, bool> dp; //ingredient/recipe is available/can be made or not
    unordered_map<string, vector<string>> req; //recipe to ingredient
    set<string> visited;
        
public:
    bool canMake(string food)
    {
        if(dp.find(food) != dp.end()) //recipe already checked / it is a supply
        {
            return dp[food];    
        }
        //if already visited then false
        if(visited.count(food))
        {
            dp[food] = false;
            return false;
        }
        
        //neither a recipe nor a supply - extra ingredient
        if(req.count(food) == 0) 
        {
            dp[food] = false;
            return false;
        }
        
        visited.insert(food);

        for(string& ing : req[food])
        {
            if(!canMake(ing))
            {
                dp[food] = false;
                return false;
            }
        }
        
        dp[food] = true;
        return dp[food];
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //first check if we have all ingredients of i in supplies
        //if not then check if there is a recipe for the missing ingredient and we have supplies for that
        //dp to store if a recipe can be made, if it is checked already or add that recipe to supplies?
        //or add supplies to dp as true
        
        //make map of recipe to ingredient for ease
        int n = recipes.size();
        for(int i=0; i<n; i++)
        {
            req[recipes[i]] = ingredients[i];
        }
        
        for(string& supply : supplies)
        {
            dp[supply] = true;
        }
        
        vector<string> possibleRecipes;
        for(int i=0; i<n; i++)
        {
            bool canBeMade = canMake(recipes[i]);
            if(canBeMade) possibleRecipes.push_back(recipes[i]);
        }
        
        return possibleRecipes;
    }
};