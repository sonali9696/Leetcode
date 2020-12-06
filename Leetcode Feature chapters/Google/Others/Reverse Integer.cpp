class Solution {
public:
    int reverse(int x) {
        long long int reversedX = 0;
        while(x != 0)
        {
            //Alternative approach  -
            if (reversedX > INT_MAX/10 || (reversedX == INT_MAX / 10 && (x%10) > 7)) return 0;
            if (reversedX < INT_MIN/10 || (reversedX == INT_MIN / 10 && (x%10) < -8)) return 0;
            
            reversedX = reversedX*10 + (x%10);
            x /= 10;
        }
            
        if(reversedX > INT_MAX || reversedX < INT_MIN) return 0; 
        return reversedX;
    }
};