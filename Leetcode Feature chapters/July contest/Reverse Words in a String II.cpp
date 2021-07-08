class Solution {
public:
    void reverseWords(vector<char>& s) {
        //reverse string
        reverse(s.begin(), s.end());
        
        //now reverse each word
        int l = s.size(), start = 0;
        for(int i=0; i<l; i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin()+start, s.begin()+i);  //i.e. from start to (i-1) index
                start = i+1;
            }
            //last word
            else if(i == l-1)
            {
                reverse(s.begin() + start, s.end());
            }
        }
        
    }
};