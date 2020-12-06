class Solution {
public:
    int reverse(int x) {
        long long int reversedX = 0;
        while(x != 0)
        {
            reversedX = reversedX*10 + (x%10);
            x /= 10;
        }
            
        if(reversedX > INT_MAX || reversedX < INT_MIN) return 0; 
        return reversedX;
    }
};