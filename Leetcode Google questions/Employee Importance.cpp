class Solution {
private:
    unordered_map<int, Employee*> m;
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* emp : employees) m[emp->id] = emp;
        return dfs(id);
    }
    
    int dfs(int id)
    {
        int ans = m[id]->importance;
        for(int subs : m[id]->subordinates){
            ans += dfs(subs);
        }
        return ans;
    }
};