//0s will come from 10 or 5*2
//number of 2s >> number of 5s so if a 5 is there 2 will definitely be there to make a 10
//10 is also a multiple of 5
//so just count multiples of 5 so one part is n/5
//now special cases like 25 = 5*5 that means it will contribute 1 extra 5 
//so 25! has 6 zeros not 5
//also 100 means one extra 10 so one extra 0
//1000 means 2 extra
//5*10 = 50 so one extra 0
//so 25/5 = 5 and if you keep dividing 5/5 = 1 so 5+1 = 6 zeroes
//50/5 = 10, 10/5 = 2 so 10+5 = 12 zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;
        
        while(n > 0)
        {
            zeroes += (n/5);
            n = n/5;
        }
        
        return zeroes;
    }
};