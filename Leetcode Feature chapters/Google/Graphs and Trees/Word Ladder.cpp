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

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        map<string,vector<string>> similarWords;
        
        if(beginWord == endWord) return 1;

        int l = beginWord.length();
        int l2 = wordList.size();
        findSimilarWords(beginWord, l, similarWords);

        for(int i=0; i < l2; i++)findSimilarWords(wordList[i], l, similarWords);

        /*map<string,vector<string>>::iterator it;
        for(it = similarWords.begin(); it != similarWords.end(); ++it)
        {
            cout<<it->first<<endl;
            vector<string> tempV = it->second;
            for(int i=0; i<tempV.size();i++) cout<<tempV[i]<<" "<<endl;
            cout<<"*********"<<endl;
        }*/
        
        map <string, bool> visited;
        for(int i=0; i<l2; i++)
        {
            visited[wordList[i]] = false;
        }

        queue<pair<string,int>> bfs;
        bfs.push(make_pair(beginWord,1));
        visited[beginWord] = true;
        int currentLevel = 1;
        
        while(!bfs.empty())
        {
            string s = (bfs.front()).first;
            currentLevel = (bfs.front()).second;
            if(s == endWord) return currentLevel;
            bfs.pop();

            //cout<<"popped "<<s<<endl;
            
            //find neighbours and push them
            string temp = s;
            for(int i=0; i<l; i++)
            {
                char currentChar = temp[i];
                temp[i] = '*';

                //cout<<"for format - "<<temp<<endl;
                vector<string> nextWords = similarWords[temp];

                for(int j=0; j<nextWords.size(); j++)
                {
                    if(visited[nextWords[j]] == false)
                    {
                        if(nextWords[j] == endWord) return currentLevel+1;
                        bfs.push(make_pair(nextWords[j],currentLevel+1));
                        visited[nextWords[j]] = true;
                        //cout<<"pushed "<<nextWords[j]<<" with level "<<currentLevel+1<<endl;
                    }
                }

                temp[i] = currentChar;
            }
        }

        return 0;
    }
};

