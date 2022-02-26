/* The knows API is defined for you.
      bool knows(int a, int b); */

// approach -
//maintain candidate[] - default = 0, cant be celebrity = -1, can be = 1
//if it is already -1 then cant change to 1.

//g[0][i] = 1 means candidate = i, candidate != 0 -> update to  different node
//g[0][i] = 0 means candidate = 0, candidate != i

//then check if isCelebrity for the candidate nodes
//the candidate node after above exercise will be only one node as we will update 0 to another node if it is not a celebrity

class Solution {
private:
    int n;
public:
    bool isCelebrity(int c)
    {
        //cout<<c<<endl;
        //c should know none, everyone should know c
        for(int i=0; i<n; i++)
        {
            if(i == c) continue;
            if(knows(c,i) || !knows(i,c)) return false;
        }
        return true;
    }
    
    int findCelebrity(int size) {
        n = size;
        int c = 0; //candidate
        
        for(int i=0; i<n; i++)
        {
            if(i == c) continue;
                
            if(knows(c,i))
            {
                //current c cant be celebrity so update it
                c = i;
            }
            //else case -> i cant be celebrity so continue;
        }
        
        if(isCelebrity(c)) return c;
        else return -1;
    }
};


//TLE - O(n^2) solution
/*class Solution {
public:
    int findCelebrity(int n) {
        
        //find person whom everybody knows
        vector<int> candidates;
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(knows(j,i) == 1) count++;
            }
            if(count == n) 
            {
                //cout<<i<<endl;
                candidates.push_back(i);
            }
        }
        
        //see if candidates dont know anyone else
        int n2 = candidates.size();
        for(int i=0; i<n2; i++)
        {
            //cout<<"cand:"<<candidates[i]<<endl;
            int count = 0;
            int person = candidates[i];
            for(int j=0; j<n; j++)
            {
                if(person == j) continue;
                if(knows(person,j) == 1) break;
                else count++;
            }
            if(count == n-1) return person;
        }
        
        return -1;
    }
};*/