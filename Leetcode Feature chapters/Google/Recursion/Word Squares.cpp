class Solution {
public:
    struct Trie{
        Trie* children[26];
        bool isEndOfWord;
	    vector<string> wordList; //index of words present here
    };
    
    Trie* init(Trie* p)
    {
        p->isEndOfWord = false;
		for(int i=0; i<26; i++) p->children[i] = NULL;
        return p;
    }
    
    Trie* insertWord(string w, Trie* root)
	{
		Trie *p = root;
		int l = w.length();
		for(int j=0; j<l; j++)
		{	
            int index = w[j] - 'a';
			if(p->children[index] == NULL)
			{
                Trie* node = new Trie();
                node = init(node);
                p->children[index] = node;
			}
			
            p = p->children[index]; //if not null, just move pointer
			(p->wordList).push_back(w);
		}
		p->isEndOfWord = true;
		return root;
	}
    	
    vector<string> wordsStartingWithW(string w, Trie* root)
    {
        Trie *p = root;
        int l = w.length();
        for(int i=0; i<l; i++)
        {
            //return if no matches except w itself
            //else append

            int index = w[i] - 'a';
            if(p->children[index] == NULL) 
            {
                vector<string> empty;
                return empty;
            }
            else p = p->children[index];
            //note wont encounter isEndOfWord as all words are of same length
            //and since w is part of word. Its length<the word length
        }

        vector<string> wordsFromHere = p->wordList;
        int n2 = wordsFromHere.size();
        /*for(int i=0; i<n2; i++)
        {
            //cout<<"words matching with "<<w<<"="<<wordsFromHere[i]<<endl;

        }*/
        //cout<<"******************"<<endl;
        return wordsFromHere;
    }    

    void backtrack(string w, vector<string> &wordSquare, int index, Trie* root, vector<vector<string>> &ans)
    {
        int l = w.length();
        //cout<<"index="<<index<<endl;
        
        wordSquare.push_back(w);
        
        /*cout<<"*****"<<endl;
        for(int i=0; i<wordSquare.size(); i++) cout<<wordSquare[i]<<endl;
        cout<<"*****"<<endl;*/
        
        index++;
        if(index == l) 
        {
            //cout<<"pushed wordsq to result"<<endl;
            ans.push_back(wordSquare);
            return;
        }
        
        //check in trie if next word fits else return false
        string prefixToBeSearched = ""; 
        for(int row=0; row <= index-1; row++)
            prefixToBeSearched = prefixToBeSearched + wordSquare[row][index];
    
        //cout<<"prefixToBeSearched="<<prefixToBeSearched<<endl;
        
        vector<string> nextWords = wordsStartingWithW(prefixToBeSearched, root);
        for(int i=0; i < nextWords.size(); i++) //if nextWords is empty, doesn't enter and directly returns
        {
            //cout<<"backtracking with "<<nextWords[i]<<endl;
            backtrack(nextWords[i], wordSquare, index, root, ans);
            wordSquare.pop_back();
        }
    }	

    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;
        
         //put words in trie
        Trie *root = new Trie();
        root = init(root);
        for(int i=0; i<n; i++) root = insertWord(words[i],root);

        
        for(int i=0; i<n; i++) 
        {
            //cout<<"checking word sq starting with "<<words[i]<<endl;
            vector<string> wordSqOfCurrWord;
            backtrack(words[i], wordSqOfCurrWord,0,root,ans);
        }

        return ans;
    }
};


