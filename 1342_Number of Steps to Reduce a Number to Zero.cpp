/*
Explanation: 
1. dividing by 2 is same as right shifting by 1. 
2. You divide by 2 when the last digit of the number is 0. 
3. If the last digit of the number is 1, that means the number is odd. In such a case you subtract by 1 i.e. make the last digit 0 from 1 and then right shift in next step (as after subtracting 1, number had become even). 
4. Thus, convert the number to binary. Count the number of 1s and 0s. 
5. For every 1, the steps needed are 2, and for every 0, the steps needed are 1. 
6. Note that the last 1 would be just 1 step not 2 as we don't need to right shift it. i.e. when number = 1, you simply do 1-1 = 0 and stop.
7. Thus the formula is (numOnes)*2 + numZeros - 1;
*/

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