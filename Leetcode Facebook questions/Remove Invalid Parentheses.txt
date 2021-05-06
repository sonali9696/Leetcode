class Solution {
private:
    vector<string> ans;
    int l;
public:
    void dfs(int index, int leftRem, int rightRem, int leftCount, int rightCount, string s, string currString){
        if(index == l){
            if((leftRem == 0 && rightRem == 0) && (leftCount == rightCount)){ 
                //leftcount=rightcount means valid string
                //leftrem,rightrem = 0 means minimum parenthesis removed
                
                //don't add duplicates - 
                if(find(ans.begin(), ans.end(), currString) == ans.end()) 
                    ans.push_back(currString);
            }
            return;
        }
        
        if(s[index] != '(' && s[index] != ')'){
            currString.push_back(s[index]);
            dfs(index+1, leftRem, rightRem,  leftCount, rightCount, s, currString);
            currString.pop_back();
        }
        else {
            
            if(s[index] == '('){
                //discarding this bracket
                if(leftRem > 0) dfs(index+1, leftRem-1, rightRem, leftCount, rightCount, s, currString);
                //keeping this bracket
                currString.push_back(s[index]);
                dfs(index+1, leftRem, rightRem, leftCount+1, rightCount, s, currString);
                currString.pop_back();
            }
            else if(s[index] == ')'){
                //discarding this bracket
                if(rightRem > 0) dfs(index+1, leftRem, rightRem-1, leftCount, rightCount, s, currString);
                //keeping this bracket -
                //can keep it if rightCount < leftCount as rightCount+1 should be a matching closing bracket to be valid
                if(rightCount < leftCount){
                    currString.push_back(s[index]);
                    dfs(index+1, leftRem, rightRem, leftCount, rightCount+1, s, currString);
                    currString.pop_back();
                }
            }
            
        }
        
        
        
    }
    
    vector<string> removeInvalidParentheses(string s){
        //number of misplaced parenthesis
        int leftRem = 0, rightRem = 0, leftCount = 0, rightCount = 0;
        l = s.length();
        for(int i=0; i<l; i++){
            if(s[i] == '('){
                leftRem++;
            }
            else if(s[i] == ')'){
                if(leftRem > 0) leftRem--;
                else rightRem++;
            }
        }
        //number of parenthesis to be removed = leftRem + rightRem

        dfs(0,leftRem,rightRem,leftCount,rightCount, s, "");


        return ans;
    }

};

