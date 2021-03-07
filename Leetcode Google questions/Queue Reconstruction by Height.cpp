//if we sort people by descending height and if same height then ascending k value
//then we can insert people one by one by index = k values
/*class Solution{
public:
    static bool sortPeople(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }
        
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        sort(people.begin(), people.end(), sortPeople);
        vector<vector<int>> q;
        
        for(vector<int> p : people){
            q.insert(q.begin()+p[1],p);
        }
        
        return q;
    }
};*/


class Solution {
public:
    static bool sortPeople(const vector<int>& a, const vector<int>& b){
        if(a[0] != b[0]) return (a[0] < b[0]); //shortest person first
        else return (a[1] > b[1]); 
        //we put k as descending so that for same height we first count spaces 
        //for a person at back of queue. Eg(7,2)
        //so that (7,0) can take a space before it without having to count if 7 is there in occupied spaces
        //if we did opp (7,0) in the first space
        //then for (7,2) we need to count 1 space + 1 occupancy of 7 to get 2  
    }
        
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), sortPeople);
        int n = people.size();
        vector<vector<int>> queue(n,vector<int>(2,-1));
        
        for(int i=0; i<n; i++){
            vector<int> person = people[i];
            int numOfTallerPeopleAhead = person[1];
            int currTallCount = -1; //so that for (7,2) it becomes 2 at the 3rd space where it is to be inserted
            
            int j;
            for(j=0; j<n; j++)
            {
                if(queue[j][0] != -1) continue; //space occupied by shorter people
                currTallCount++;
                if(currTallCount == numOfTallerPeopleAhead) break;
            }
            queue[j] = person;
        }
        
        return queue;
    }
};