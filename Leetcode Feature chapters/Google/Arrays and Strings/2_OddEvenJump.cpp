
class Solution {
public:
    
    int oddEvenJumps(vector<int>& A) {
        int n = A.size(), numOfGoodIndices = 1;
        
        if(n == 0) return 0;
        
        vector<int> oddJump_isGoodIndex(n), evenJump_isGoodIndex(n);
        for(int i=0; i<n; i++)
        {
            oddJump_isGoodIndex[i] = 0;
            evenJump_isGoodIndex[i] = 0;
        }
        
        oddJump_isGoodIndex[n-1] = 1, evenJump_isGoodIndex[n-1] = 1; //true
        
        map<int, int> processedNumbersMap;
        processedNumbersMap[A[n-1]] = n-1; 
        //we will traverse in reverse so for repeating numbers, this will have corresponding lower index
        
        for(int i = n-2; i >= 0; --i)
        {
            auto greaterEqNumIterator = processedNumbersMap.lower_bound(A[i]);
            
            if(greaterEqNumIterator != processedNumbersMap.end())
                oddJump_isGoodIndex[i] = evenJump_isGoodIndex[greaterEqNumIterator->second]; //at A[j] >= A[i]
            
            auto greaterNumIterator = processedNumbersMap.upper_bound(A[i]);

            if(greaterNumIterator != processedNumbersMap.begin()) //as -- would be out of bounds
            {
                greaterNumIterator--;
                evenJump_isGoodIndex[i] = oddJump_isGoodIndex[greaterNumIterator->second]; //at A[j] <= A[i]
            }
            
            if(oddJump_isGoodIndex[i]) numOfGoodIndices++;
            
            processedNumbersMap[A[i]] = i;
        }
        
        return numOfGoodIndices;
    }
};

