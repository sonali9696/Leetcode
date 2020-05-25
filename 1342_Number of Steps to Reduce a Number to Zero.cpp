class Solution {
public:
    int numberOfSteps (int num) {
        long long int numOfSteps = 0;

        //count 1s and 0s when number is converted to binary
        int numOnes = 0, numZeros = 0;
        
        while(num != 0)
        {
            if(num % 2 == 0) numZeros++;
            else numOnes++;
            
            num /= 2;
        }
        
        numOfSteps = (numOnes)*2 + numZeros;
        numOfSteps--; //as the last 1 will take 1 step not 0 as it doesn't need to be right shifted.
        //1 in binary: odd stage so: -1 and right shifted (/2)
        //0 in binary: even stage so only /2
        
        return numOfSteps;
    }
};