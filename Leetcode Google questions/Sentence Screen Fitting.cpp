class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        
        vector<int> sentenceLen;
        for(int i=0; i<n; i++) 
        {
            int l = sentence[i].length();
            sentenceLen.push_back(l);
            if(l > cols) return 0; //not possible to fit in any row
        }

        int index = 0, totalWords = 0, i = 0;
        map<int,int> countWithThisStartWord; //pos of start word, # of words fitting in that line
        
        while(i < rows)
        {
            if(countWithThisStartWord.find(index) != countWithThisStartWord.end())
            {
                totalWords += countWithThisStartWord[index];
                i++; //next row
                index = (index+countWithThisStartWord[index])%n; //next word for next row
                
                continue;
            }
            
            //if not precalculated -
            int l = sentenceLen[index], j = 0, currCount=0, start = index;
            
            while(j + l <= cols) 
            {
                j += (l+1); //insert word and space
                totalWords++;
                currCount++;
                
                //next word
                index = (index+1)%n;
                l = sentenceLen[index];
            }
            countWithThisStartWord[start] = currCount;
            i++;//next row
        }
        
        return (totalWords/n);
    }
};


/*
good test cases - 

["hello","world"]
2
8

["a", "bcd", "e"]
3
6

["I", "had", "apple", "pie"]
4
5

["I", "had", "apple", "pie"]
4
4

["a", "bcd", "e"]
1
6

["try","to","be","better"]
10
9*/