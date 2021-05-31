class Solution {
private:
    int leftP = -1, rightP = -1;
public:
    void findPalindrome(int left, int right, string &s)
    {
        int l = s.length();
        while(left >= 0 && right < l && s[left] == s[right])
        {
            left--;
            right++;
        }
        //reset to the last correct value
        left++;
        right--;
        
        if(rightP == -1 || (right-left+1 > rightP - leftP + 1))
        {
            rightP = right;
            leftP = left;
        }
    }
    
    string longestPalindrome(string s) {
        int l = s.length();
        string curr;
        int left, right;
        
        //find if pos is mid of a palindrome
        for(int i=0; i <= l-1; i++)
        {
            findPalindrome(i,i,s); //includes trivial case of single letter as palindrome
            if(i != 0 && s[i-1] == s[i]) findPalindrome(i-1,i,s);
        }
        
        string palindrome = "";
        if(rightP != -1) palindrome = s.substr(leftP,rightP-leftP+1);
        return palindrome;        
    }
};

