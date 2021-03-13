class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (b.empty()) return 0;
        
        std::vector<int> t; //lps array
        t.reserve(b.size());
        int i = 0;
        int j = 1;
        t.push_back(0);
        while(j<b.size())
        {
		   // match, move two indices together
            if (b[i]==b[j])
            {
                t.push_back(i+1);
                ++i;
                ++j;
            }
			// i cannot go back anymore, just increase j
            else if (i==0)
            {
                t.push_back(0);
                ++j;
            }
            else
            {
			   // move index i back based on table index
                i = t[i-1];
            }
        }
        
        i = 0;
        j = 0;
        // i traverses the pattern, j traverses the text
        // j never retraverse, i can go back and forth
        // this loop is ensentially the same as above but just traversing two strings instead of the same one
        while (j < a.size() + b.size())
        {
            if (i == b.size())
            {
                return (j - 1) / a.size() + 1;// this formula is different
            }
            // match, move two indices together
            if (a[j%a.size()] == b[i])
            {
                ++j;
                ++i;
            }
			// i cannot go back anymore, just increase j
            else if (i == 0)
            {
                ++j;
            }
			// move index i back based on table index
            else if (i > 0)
            {
                i = t[i - 1];
            }
        }
        
        return -1;
        
    }
};

/*class Solution {
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
};*/

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