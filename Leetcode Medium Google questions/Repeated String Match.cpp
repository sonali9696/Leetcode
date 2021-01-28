class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        for (int i = 0; i < A.length(); i++) {
            if (A[i] == B[0]) {
                int count = 1;
                int j = 0;
                int startIx = i;
                while (j < B.length() && A[startIx] == B[j]) {
                    j++;
                    startIx++;
                    if (startIx >= A.length() && j < B.length()) {
                        startIx = 0;
                        count++;
                    }
                }
                if (j == B.length()) return count;
            }
        }
        return -1;
    }
};

/*good test cases-
"abcd"
"cdabcdab"

"cdab"
"cdabcdab"

"a"
"aa"

"a"
"a"


"abc"
"wxyz"

"aba"
"baaba"

"aa"
"a"

"abc"
"cabcabca"

"aaaaaaaaaaaaaaaaaaaaaab"
"ba"
*/