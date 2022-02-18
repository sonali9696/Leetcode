//when single digit - check 1 then true 
//else if it gets to 4 then willl get stuck in cycle so return false
//this pattern was found by observing pattern in output for 1 to 9

class Solution {
public:
    bool isHappy(int n) {
        //cout<<n<<endl;
        
        if(n/10 == 0) //single digit
        {
            if(n == 1) return true;
            else if(n == 4) return false; //single digit numbers start repeating cycles beginning at 4
            //else return false;
        }
        
        long long int newNum = 0;
        while(n > 0)
        {
            newNum += pow((n % 10),2);
            n /= 10;
        }
        
        return isHappy(newNum);
    }
};