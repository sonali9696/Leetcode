class Solution {
private:
    vector<string> parenthesisCombos;
public:
    void createParenthesisCombos(string s,int open,int closed, int n)
    {
        //cout<<"s="<<s<<",open="<<open<<",closed="<<closed<<",n="<<n<<endl;
        if(closed == n) 
        {
            //cout<<"********"<<s<<"********"<<endl;
            parenthesisCombos.push_back(s);
            return;
        }
        if(open == n)
        {
            while(closed != n)
            {
                s.push_back(')');
                closed++;
            }
            //cout<<"********"<<s<<"********"<<endl;
            parenthesisCombos.push_back(s);
            return;
        }
        
        if(closed + 1 <= open)
        {
            createParenthesisCombos(s+')',open,closed+1,n);
        }
        createParenthesisCombos(s+'(',open+1,closed,n);
    }
    
    vector<string> generateParenthesis(int n) {
        int open = 1, closed = 0;
        string s = "(";
        createParenthesisCombos(s,open,closed,n);        
        return parenthesisCombos;
    }
};

