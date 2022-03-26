//solution 2: using bitmask
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> start;
        for(int i=0, m=startWords.size(); i<m; i++)
        {
            start.insert(getBits(startWords[i]).to_ulong());
        }
        
        int ans = 0;
        for(int i=0, n=targetWords.size(); i<n; i++)
        {
            auto bits = getBits(targetWords[i]);
            for(int c=0; c<26; c++)
            {
                if(bits[c])
                {
                    bits[c] = 0;
                    if(start.find(bits.to_ulong()) != start.end())
                    {
                        ans++;
                        break;
                    }
                    bits[c] = 1;
                }
            }
        }
        
        return ans;
    }
    
    bitset<26> getBits(string word)
    {
        bitset<26> bits;
        for(int c=0, l=word.length(); c<l; c++)
        {
            bits.set(word[c] - 'a', 1);
        }
        
        return bits;
    }
};


//Put all words from startWords in trie for quick comparison with targetwords
//before putting, sort all words in startWords so that rearrangement doesnt make a difference
//now for targetwords, we search all combos of it in trie
//combos is the same word without one of its letter
//this helps to find whether there is any startWord which is same as targetWord except one letter (when both are sorted)

/*class Solution {
public:
    struct Trie{
        bool isLeaf;
        Trie* children[26];
    };
    
    Trie* createNode()
    {
        Trie* t = new Trie();
        t->isLeaf = false;
        for(int i=0; i<26; i++)
        {
            t->children[i] = NULL;
        }
        return t;
    }
    
    Trie* insertIntoTrie(Trie* root, string s)
    {
        Trie* ptr = root;
        int l = s.length();
        for(int i=0; i<l; i++)
        {
            char c = s[i];
            if(ptr->children[c-'a'] == NULL)
            {
                ptr->children[c-'a'] = createNode();
            }
            
            ptr = ptr->children[c-'a'];
        }
        
        ptr->isLeaf = true;
        return root;
    }
    
    bool searchInTrie(Trie* root, string t)
    {
        Trie* ptr = root;
        int l = t.length();
        for(int i=0; i<l; i++)
        {
            char c = t[i];
            if(ptr->children[c-'a'] == NULL) return false;
            
            ptr = ptr->children[c-'a'];
        }
        
        if(ptr->isLeaf) return true;
        else return false;
    }
    
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        Trie *root = createNode();
        
        for(string s : startWords)
        {
            sort(s.begin(), s.end());
            root = insertIntoTrie(root, s);
        }
        
        int numOfReqWords = 0;
        
        for(string t : targetWords)
        {
            sort(t.begin(), t.end());
            int n = t.length();
            if(n == 1) continue; //cant obtain from startWord as min startWord len is 1
            
            for(int i=0; i<n; i++)
            {
                string currSearchWord;
                
                if(i == 0) currSearchWord = t.substr(1);
                else currSearchWord = t.substr(0,i) + t.substr(i+1);
                
                bool exists = searchInTrie(root, currSearchWord);
                if(exists) 
                {
                    numOfReqWords++;
                    break;
                }
            }
        }
        
        return numOfReqWords;
    }
};*/