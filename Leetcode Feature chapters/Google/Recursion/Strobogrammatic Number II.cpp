//pattern is that it starts and ends with: [0,0], [1,1], [6,9], [8,8], [9,6]
//the pattern between it is the same as solution for n-2.
//only for subproblems [0,0] is used.
//final solution for n we have to remove the numbers that start and end with 0 
//as starting with 0 means essentially having less than n digits 

class Solution {
private:
    string begin[5] = {"0","1","6","8","9"};
    string end[5] = {"0","1","9","8","6"};
    
public:
    vector<string> createStrobogrammaticNumbers(int n)
    {
        //cout<<"n="<<n<<endl;
        
        vector<string> numbers;
        if(n == 0) 
        {
            numbers = {""};
            return numbers;
        }
        if(n == 1) 
        {
            numbers = {"0","1","8"};
            return numbers;
        }
        else if(n == 2)
        {
            //cout<<"here "<<endl;
            numbers = {"00","11","69","88","96"};
            //cout<<numbers.size()<<endl;
            return numbers;
        }
        else
        {
            vector<string> resultNMinus2 = createStrobogrammaticNumbers(n-2);
            for(int i=0; i<5; i++)
            {
                for(int j=0; j < resultNMinus2.size(); j++)
                {
                    string middle = resultNMinus2[j];
                    //cout<<"middle="<<middle<<endl;
                    string s = begin[i];
                    for(int k=0; k<middle.length(); k++) s = s + middle[k];
                    s = s + end[i];
                    //cout<<"pushing "<<s<<endl;
                    //cout<<"***"<<endl;
                    numbers.push_back(s);
                }
            }
        }
        
        return numbers;
    }
    
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans = createStrobogrammaticNumbers(n);
        //cout<<ans.size()<<endl;
        
        //TODO: CHECK HOW TO REMOVE 0TH INDEX ONES
        if(n > 1)
        {
            int endIndex;
            for(int i=0; i<ans.size(); i++)
            {
                string s = ans[i];
                //cout<<s<<endl;
                if(s[0] == '0' && s[s.length()-1] == '0')
                {
                    endIndex = i;
                }
                else break;
            }
            ans.erase(ans.begin(), ans.begin()+(endIndex+1)); //0 till endIndex removed
        }
        
        
        return ans;
    }
};

