class Trie{
private:
	struct TrieNode{
		bool isLeaf = false;
		int times = 0;
		TrieNode* children[27];
    };

    TrieNode* root;

public:
	Trie()
    {
        root = new TrieNode();
        for(int i=0; i<27; i++) root->children[i] = NULL;
    }

    void addStringToTrie(string s, int count)
    {
        //cout<<"to add:"<<s<<endl;
        int l = s.length(),index;
        TrieNode* p = root;
        for(int i=0; i<l; i++)
        {
            if(s[i] == ' ') index = 26;
            else index = s[i] - 'a';
            if(p->children[index] == NULL)
            {
                TrieNode *newNode = new TrieNode();
                p->children[index] = newNode;
                for(int i=0; i<27; i++) newNode->children[i] = NULL;
                //cout<<"new node created "<<index<<" "<<s[i]<<endl;
            }

            p = p->children[index];
        }

        p->isLeaf = true;
        p->times += count;
        //cout<<"times="<<p->times<<endl;
        //cout<<"********************"<<endl;
    }

    //search prefix in trie and return list of all sentences
    vector<pair<string,int> > findPrefixInTrie(string searchTerm)
    {
        int l = searchTerm.length();
        vector<pair<string,int> > suggestions;
        TrieNode* p = root;
        for(int i=0; i<l; i++)	
        {
            int index;
            if(searchTerm[i] == ' ') index = 26;
            else index = searchTerm[i] - 'a';
            if(p->children[index] == NULL) return suggestions;
            else p = p->children[index];
        }

        if(p->isLeaf == true) suggestions.push_back(make_pair(searchTerm,p->times));

        //get all sentences from here
        for(int i=0; i<27; i++)
        {
            if(p->children[i] != NULL)
            {
                char c;
                if(i < 26) c = i + 'a';
                else c = ' ';
                reachLeaf(searchTerm+c,suggestions,p->children[i]);
            }
        }

        return suggestions;
    }

    void reachLeaf(string currString,vector<pair<string,int> > &suggestions, TrieNode* p)
    {
        if(p->isLeaf == true) suggestions.push_back(make_pair(currString,p->times));

        int count = 0;
        for(int i=0; i<27; i++)
        {
            if(p->children[i] != NULL) 
            {
                char c;
                if(i < 26) c = i + 'a';
                else c = ' ';
                reachLeaf(currString+c,suggestions,p->children[i]);
            }
        }
    }
};

class AutocompleteSystem {
private:
	string searchTerm;
    Trie t;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        searchTerm = "";
        int l = sentences.size();
        for(int i=0; i<l; i++) t.addStringToTrie(sentences[i],times[i]);
    }
    
    static bool sortByTimes(const pair<string,int> &p1, const pair<string,int> &p2)
	{
		if(p1.second == p2.second) return p1.first < p2.first;
		else return p1.second > p2.second;
    }

    vector<string> input(char c) {
       	if(c == '#')
		{
            t.addStringToTrie(searchTerm,1);
			searchTerm = "";
			vector<string> empty;
			return empty;
		}
		
		searchTerm += c;
		vector<pair<string,int> > suggestions = t.findPrefixInTrie(searchTerm);
	
		//sort vector acc to times, and ascii
		sort(suggestions.begin(),suggestions.end(),sortByTimes);

		//take first 3 or full if size < 3
		vector<string> result;

		//append to result
        int size = 3 < suggestions.size()?3:suggestions.size();
		for(int i=0; i < size; i++) result.push_back(suggestions[i].first);
		
		return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

