//Note: question means that L-left facing ppl, R-right facing, X-empty space
//L and R can't cross each other, they can only move in empty spaces
//XL->LX means L can only move further left
//RX->XR means R can move further right only

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int numOfX = 0;
        for(int i=0; i<n; i++) //number of Xs should be same in both
        {
            if(start[i] == 'X') numOfX++;
            if(end[i] == 'X') numOfX--;
        }
        if(numOfX != 0) return false;
        
        int i = 0, j = 0;
        while(i < n && j < n)
        {
            while(i<n && start[i] == 'X') i++;
            while(j<n && end[j] == 'X') j++;
            
            if(i == n || j == n) return (i == n && j == n); 
            
            if(start[i] != end[j]) return false; //order of L and R should be same without X
            
            if(start[i] == 'L' && i < j) return false; //XL->LX only allowed not LX->XL
            if(end[j] == 'R' && i > j) return false;
                
            i++;
            j++;
        }

        return true;  
    }
};

