class Solution {
public:
    double fastPow(double x, long long int n)
    {
        //square of x^(n/2)=x^n
        //so recursively doing that will give O(log n) instead of O(n)
        
        //if n is even then above works
        //else above*x. 
        //eg: x^5=(x^2)^2 * x
        
        if(n == 0) return 1;
        double half = fastPow(x,n/2);
        
        if(n % 2 == 0) //even
        {
           return (half*half);
        }
        else
        {
            return (half*half*x);
        }
    }
    
    double myPow(double x, int n) {
        if(n == 0) return 1;
        long long int power = n;
        
        if(n<0)
        {
            x = (1.0/x);
            power = (-power);
        }
        
        return fastPow(x, power);
        
        
        /*double ans = 1.0;
        if(n==0) return 1.0;
        
        for(int i=1; i<=abs(n);i++) ans *= x;
        //cout<<ans<<endl;
        if(n<0) return (1.0/ans);
        else return ans;*/
    
    }
};