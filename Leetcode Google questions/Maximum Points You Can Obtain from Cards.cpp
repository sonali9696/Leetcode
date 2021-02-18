class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0, maxScore = 0;
        int n = cardPoints.size();
        if(n < k) return 0;
        
        int i, j=n-1;
        
        //score of all k cards from left side
        for(i=0; i<k; i++) score += cardPoints[i];
        i--; //to reset the i as k-1 as i++ put it one step ahead
        maxScore = max(maxScore, score);
        
        //taking cards from right and leaving out from left
        while(i >= 0)
        {
            score = (score - cardPoints[i]) + cardPoints[j];
            maxScore = max(maxScore, score);
            i--;
            j--;
        }
        
        return maxScore;
    }
};