class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size();
        vector<int> candies(l,1);
        if(l == 0 || l == 1) return l;

        for(int i=1; i<l; i++)
        {
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1; //left2right
            //no need to check candies[i] <= candies[i-1] because
            //initially all were 1 so candies[i-1] may be 1 or updated to greater value
            //candies[i] would be 1 so it will always be <= candies[i-1]
        }
        
        int totalCandies = candies[l-1];
        for(int i=l-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) 
                candies[i] = max(candies[i], candies[i+1] + 1); //right2left
            totalCandies += candies[i];
        }

        return totalCandies;
    }
};

/*class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size(), totalCandies = 0;
        vector<int> left2right(l,1), right2left(l,1);
        if(l == 0 || l == 1) return l;

        for(int i=1; i<l; i++)
        {
            if(ratings[i] > ratings[i-1]) left2right[i] = left2right[i-1]+1;
        }

        for(int i=l-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1]) right2left[i] = right2left[i+1]+1;
        }
        
        for(int i=0; i<l; i++) totalCandies += max(left2right[i],right2left[i]); 

        return totalCandies;
    }
};*/



/*TLE:

class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size(), totalCandies = 0;
        vector<int> candies(l,1);
        if(l == 0 || l == 1) return l;

        if(ratings[1] > ratings[0]) 
        {
            candies[0] = 1;
            candies[1] = 2;
        }
        else if(ratings[1] == ratings[0]) candies[0] = candies[1] = 1;
        else if(ratings[1] < ratings[0])
        {
            candies[0] = 2;
            candies[1] = 1;
        }
        
        for(int i=2; i <l; i++)
        {
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;
            else if(ratings[i] == ratings[i-1]) candies[i] = 1;
            else
            {
                if(candies[i-1]-1 >= 1) candies[i] = 1;
                else
                {
                    candies[i] = 1;
                    int j = i-1;
                    while(j >= 0 && ratings[j] > ratings[j+1])
                    {
                        if(candies[j] > candies[j+1]) break;
                        candies[j] = candies[j+1]+1;
                        j--;
                    }
                }
            }
        }
        
        for(int i=0; i<l; i++)
        {
            totalCandies += candies[i];
            cout<<candies[i]<<endl;
        }
        
        return totalCandies;
    }
};*/

