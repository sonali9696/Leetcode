class Solution {
public:
    int reverse(int x) {
        long long int reversedX = 0;
        while(x != 0)
        {
            long long int temp = reversedX*10 + (x%10);
            if(temp > (pow(2,31)-1) || temp < -(pow(2,31))) return 0;
            reversedX = temp;
            
            x /= 10;
        }
            
        if(reversedX > (pow(2,31)-1) || reversedX < -(pow(2,31))) return 0; 
        return reversedX;
    }
};