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