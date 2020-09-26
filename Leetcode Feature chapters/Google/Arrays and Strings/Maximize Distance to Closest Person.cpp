class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> occupiedPositions;

        int n = seats.size();
        for(int i=0; i<n; i++)
        {
            if(seats[i] == 1) occupiedPositions.push_back(i);
        }

        int n2 = occupiedPositions.size();
        int maxDist = 0;
        if(occupiedPositions[0] - 0 > maxDist) maxDist = occupiedPositions[0] - 0;
        if(n-1 - occupiedPositions[n2-1] > maxDist) maxDist = n-1 - occupiedPositions[n2-1];

        for(int i=1; i<n2; i++)
        {
            int diffBy2 = (occupiedPositions[i] - occupiedPositions[i-1])/2;
            if(diffBy2 > maxDist) maxDist = diffBy2;
        }

        return maxDist;
    }

};