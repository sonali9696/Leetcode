//for it to be possible count of that number has to be n.
//minimum rotations is the lower value of A or B.

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        map<int,int> countInA, countInB, countInEqual;
        int minRotation = INT_MAX;

        int n = A.size();
        for(int i=0; i<n; i++)
        {
            if(A[i] == B[i])
            {
                if(countInEqual.find(A[i]) == countInEqual.end()) countInEqual[A[i]] = 1;
                else countInEqual[A[i]]++;
            }
            else 
            {
                if(countInA.find(A[i]) == countInA.end()) countInA[A[i]] = 1;
                else countInA[A[i]]++;

                if(countInB.find(B[i]) == countInB.end()) countInB[B[i]] = 1;
                else countInB[B[i]]++;
            }

            if(countInA[A[i]] + countInB[A[i]] + countInEqual[A[i]] == n) //A[i] is possible same value
            {
                minRotation = min(minRotation, min(countInA[A[i]], countInB[A[i]])); 
                //count in equal needs no rotation
            }
            else if(countInA[B[i]] + countInB[B[i]] + countInEqual[B[i]] == n) //B[i] is possible same value
            {
                minRotation = min(minRotation, min(countInA[B[i]], countInB[B[i]]));
            }
        }

        if(minRotation == INT_MAX) return -1;
        else return minRotation;
    }
};

