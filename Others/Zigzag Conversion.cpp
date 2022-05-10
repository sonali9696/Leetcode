//my approach:
//for first and last row, indices increase by 2n-2
//for each subsequent row, this increment factor reduces by 2 
//and alternates with (2n-2) - increment factor

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int increment = 2 * numRows - 2;

        for (int i = 0; i < numRows && i < n; i++) { //startIndex
            
            if(i == 0 || i == numRows-1) increment = 2 * numRows - 2;
            else 
            {
                increment -= 2;
            }
            
            int j = i;
            ret += s[j];
            
            while(j < n)
            {    
                j += increment;
                if(j >= n) break;
                else ret += s[j];
                
                if(i == 0 || i == numRows-1) continue;
                
                j += (2 * numRows - 2 - increment);
                if(j >= n) break;
                else ret += s[j];
            }
            
        }
        return ret;
    }
};



//approach 2: assign output directly row by row
//for that calculate relations between indices
//1st row: starts with 2n-2 where n = number of rows
//last row i.e. n-1 row: 2n-2 + (n-1)
//inner row: alternating between 2n-2 + i and (k+1)(2n-2)-i
/*class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};*/

//directly writing the characters in the rows by iterating through string
//then reading it row by row
/*class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};*/