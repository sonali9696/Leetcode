class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char,char> inverted;
        
        inverted['0'] = '0';
        inverted['1'] = '1';
        inverted['8'] = '8';
        
        inverted['6'] = '9';
        inverted['9'] = '6';
        
        int l = num.length();
        for(int i=l-1, j=0; i>=0; i--,j++)
        {
            if(inverted[num[i]] != num[j]) return false; //covers cases where number not in inverted map
        }
        return true;
    }
};