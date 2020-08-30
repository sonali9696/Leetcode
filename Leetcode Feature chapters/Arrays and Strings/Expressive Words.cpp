class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<char> lettersInS;        
        vector<int> freqOfLettersInS; 

        int n = S.length(), pos = 0;
        lettersInS.push_back(S[0]);
        freqOfLettersInS.push_back(1);

        //store freq of letters in S
        for(int i=1; i<n; i++)
        {
            if(S[i] == S[i-1]) freqOfLettersInS[pos]++;
            else
            {
                pos++;
                lettersInS.push_back(S[i]);
                freqOfLettersInS.push_back(1);
            }
        }

        
        int numOfWords = words.size(), numOfFreq = freqOfLettersInS.size();
        int ans = 0;

        for(int w = 0; w < numOfWords; w++)
        {
            string word = words[w];
            
            char currentChar = word[0];
            char currentFreq = 1;
            pos = 0;
            int i = 1, wordLen = word.length(); 

            while(i < wordLen && pos < numOfFreq)
            {
                if(currentChar != lettersInS[pos]) break;
                if(word[i] == word[i-1]) currentFreq++;
                else
                {
                    //compare 
                    if(currentFreq != freqOfLettersInS[pos] && freqOfLettersInS[pos] < 3) break;
                    if(currentFreq > freqOfLettersInS[pos]) break;
                    pos++;
                    currentChar = word[i];
                    currentFreq = 1;
                }
                i++;
            }

            if(i == wordLen && pos == numOfFreq-1 && word[i-1] == lettersInS[pos] && (currentFreq == freqOfLettersInS[pos] || (freqOfLettersInS[pos] >= 3 && freqOfLettersInS[pos] > currentFreq))) 
            {
                ans++;
            }
        }

        return ans;
        }


};