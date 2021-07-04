class Solution {
public:
    int countVowelPermutation(int n) {
        long long int currCount = 5, currLen = 1, aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        
        while(currLen != n){
            currLen++;
            
            long long int aCountNew, eCountNew, iCountNew, oCountNew, uCountNew;
            aCountNew = (eCount + iCount + uCount)  % (long long int)(pow(10,9) + 7);
            eCountNew = (aCount + iCount) % (long long int)(pow(10,9) + 7);
            iCountNew = (eCount + oCount) % (long long int)(pow(10,9) + 7);
            oCountNew = iCount % (long long int)(pow(10,9) + 7);
            uCountNew = (iCount + oCount) % (long long int)(pow(10,9) + 7);
            
            currCount = aCountNew + eCountNew + iCountNew + oCountNew + uCountNew;
            
            aCount = aCountNew;
            eCount = eCountNew;
            iCount = iCountNew;
            oCount = oCountNew;
            uCount = uCountNew;
        }
        
        return (currCount % (long long int)(pow(10,9) + 7));
    }
};