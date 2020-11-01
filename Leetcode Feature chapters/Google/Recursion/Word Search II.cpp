//add words to trie
//iterate 2D array 
//find if there exists word starting with letter in cell
//check its neighbours and see if those neighbours exist in trie
//if yes iterate and recurse
//if found complete word by this, add to ans

class Solution {
private:
	int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
public:
    struct Trie{
        Trie* children[26];
        bool isEndOfWord;
    };
	
	Trie* init(Trie* p)
	{
		for(int i=0; i<26; i++) p->children[i] = NULL;
		p->isEndOfWord = false;
		return p;
	}
	
	Trie* insertTrie(string s, Trie* root)
	{
		int l = s.length();
		Trie* p = root;
		for(int j=0; j<l; j++)
		{
			int index = s[j] - 'a';
			if(p->children[index] == NULL)
			{
				Trie *node = new Trie();
				node = init(node);
                p->children[index] = node;
			}
			p = p->children[index];
		}
		p->isEndOfWord = true;
		
		return root;
	}

	void findInTrie(int row,int col,string s,vector<vector<char>>& board,vector<string>& wordsFound, Trie* root, vector<vector<bool>> visited)
    {
		Trie *p = root;
		char c = board[row][col];
		int index = c - 'a';
		if(p->children[index] == NULL) return; //not in words/trie
		else
		{
            visited[row][col] = true;
			p = p->children[index];
			if(p->isEndOfWord == true)
			{
                //don't push duplicate even if it exists twice in crossword
                if(find(wordsFound.begin(),wordsFound.end(),s) == wordsFound.end())
				    wordsFound.push_back(s);
				//return; //maybe aaa and aaab both are words so cant stop at aaa
			}
			
			//find neighbours and recurse
			for(int i=0; i<4; i++)
			{
				int newRow = row+dir[i][0];
				int newCol = col+dir[i][1];
                if(newRow < 0 || newRow >= board.size()) continue;
                if(newCol < 0 || newCol >= board[0].size()) continue;
                if(visited[newRow][newCol] == true) continue;
				s.push_back(board[newRow][newCol]);
				findInTrie(newRow,newCol,s,board,wordsFound,p,visited);
				s.pop_back();
			}
		}
        
        //optimization: removing leaf nodes which we already processed
        bool isLeaf = true;
        for(int i = 0; i<26; i++)
        {
            if(p->children[i] != NULL)
            {
                isLeaf = false;
                break;
            }
        }
        if(isLeaf)
        {
            p = NULL;
        }
	}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	vector<string> wordsFound;
        if(board.size() == 0 || board[0].size() == 0) return wordsFound;
        int numOfWords = words.size();
        Trie* root = new Trie();
        root = init(root);

        for(int i=0; i< numOfWords; i++) root = insertTrie(words[i],root);

        int R = board.size(), C = board[0].size();
        
        vector<vector<bool>> visited;
        for(int i=0; i<R; i++)
        {
            vector<bool> temp;
            for(int j=0; j<C; j++) temp.push_back(false);
            visited.push_back(temp);
        }
        
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                char cell = board[i][j];
                string s;
                s.push_back(cell);
                findInTrie(i,j,s,board,wordsFound,root,visited);
            }
        }
        return wordsFound;
    }
};

