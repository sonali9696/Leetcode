void findSimilarWords(string s, int l, map<string,vector<string>> &similarWords)
{
	string temp = s;
	//store generic forms of the words like dog - *og, d*g, do*
	for(int i=0; i<l; i++)
	{
		char currentChar = temp[i];
		temp[i] = '*';
		
		similarWords[temp].push_back(s);
		
		temp[i] = currentChar;
	}

}

int bfsTraverse(queue<pair<string,int>> &bfs, map<string, int> &visited, map<string, int> &visitedOtherDirection, map<string,vector<string>> &similarWords)
{
    string s = (bfs.front()).first;
    int currentLevel = (bfs.front()).second;
    bfs.pop();
    
    //find neighbours and push them
    string temp = s;
    int l = s.length();
    for(int i=0; i<l; i++)
    {
        char currentChar = temp[i];
        temp[i] = '*';

        //cout<<"for format - "<<temp<<endl;
        vector<string> nextWords = similarWords[temp];

        for(int j=0; j<nextWords.size(); j++)
        {
            if(nextWords[j] == s) continue;
            
            if(visitedOtherDirection.find(nextWords[j]) != visitedOtherDirection.end())
            {
                return currentLevel + (visitedOtherDirection[nextWords[j]]);
            }
            
            if(visited.find(nextWords[j]) == visited.end())
            {
                
                bfs.push(make_pair(nextWords[j],currentLevel+1));
                visited[nextWords[j]] = currentLevel+1;
                //cout<<"pushed "<<nextWords[j]<<" with level "<<currentLevel+1<<endl;
            }
        }

        temp[i] = currentChar;
    }
    
    return -1;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Note: beginWord need not be in dictionary but end word has to be
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        int l2 = wordList.size();
        map<string,vector<string>> similarWords;
        
        if(beginWord == endWord) return 1;

        int l = beginWord.length();
        findSimilarWords(beginWord, l, similarWords);

        for(int i=0; i < l2; i++)
        {
            findSimilarWords(wordList[i], l, similarWords);
        }

        //we are doing bidirectional bfs i.e. starting from beginWord and the other is starting from endWord
        map<string, int> visitedBegin, visitedEnd; //word, level

        queue<pair<string,int>> bfsBegin;
        bfsBegin.push(make_pair(beginWord,1));
        visitedBegin[beginWord] = 1;
        
        queue<pair<string,int>> bfsEnd;
        bfsEnd.push(make_pair(endWord,1));
        visitedEnd[endWord] = 1;
        
        while(!bfsBegin.empty() && !bfsEnd.empty())
        {
            int ans = bfsTraverse(bfsBegin, visitedBegin, visitedEnd, similarWords);
            if(ans > -1) return ans;
            
            ans = bfsTraverse(bfsEnd, visitedEnd, visitedBegin, similarWords);
            if(ans > -1) return ans;   
        }

        return 0;
    }
};

