class Solution {
public:
    int getSum(int a, int b) {
        long mask = 0xFFFFFFFF;
        
        //if a,b are +ve then it is a+b
        //if a is negative, b positive then it is -a+b i.e. subtraction
        
        //for addition: a xor b gives value of addition/subtraction without carry
        //carry is (a&b)<<1 for addition, (~a&b)<<1 for subtraction where a>b
        //so ans is first part + carry which is another sum question
        //so keep doing it until carry !=0
        
        //now instead of handling positive and negative separately we can & it with mask (1111.. 32 times)
        //this handles both
        
        
        while (b != 0) {
            int answer = (a ^ b) & mask; 
            int carry = ((a & b) & mask) << 1;
            a = answer;
            b = carry;
        }
         
        return a < INT_MAX ? a : ~(a ^ mask); //handles overflow
    }
};
/*class Solution {
public:
    int getSum(int a, int b) {
        //a+b = log10(10^(a+b)) = log10(10^a * 10^b)
        
        if(b == 0) return a;
        else if(a == 0) return b;
        
        double part1 = pow(10,a)*pow(10,b);
        double part2 = log10(part1);
        
        return (int)part2;
    }
};*/