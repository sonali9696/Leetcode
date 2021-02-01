class ValidWordAbbr {
private:
	map<string,bool> abbreviations; //abbrevation, 1 or more than 1 words
    //set is used so that duplicates are not stored
    set<string> dict;

	string abbreviate(string word)
	{
		string ans = "";
        ans.push_back(word[0]);
		int l = word.length(), count=0;
		for(int i=1; i <= l-2; i++) count++;
		if(count != 0)ans += to_string(count);
		ans.push_back(word[l-1]);
		return ans;
	}

public:
    ValidWordAbbr(vector<string>& dictionary) {
        //to remove duplicates-
        for(string w : dictionary) dict.insert(w);
        
        set<string>::iterator it;
		for(it = dict.begin(); it != dict.end(); it++)
		{
			string abbr = abbreviate(*it);
            if(abbreviations.find(abbr) == abbreviations.end())
                abbreviations[abbr] = true;
			else abbreviations[abbr] = false; //two words with same abbr
		}
    }
    
    bool isUnique(string word) {
		string abbr = abbreviate(word);
		if(abbreviations.find(abbr) == abbreviations.end()) return true;
		else
		{
			bool singleWord = abbreviations[abbr];
			//if 2 words say deer,door have same abbreviation and word is deer then it is saying to return false maybe because of door so if 2 or more words have same abbr then not possible to check that condition so all words in vector has to be this word
            
            if(singleWord == false) return false;
            else
            {
                //check if word is in dict 
                //if yes means it is the only word
                if(dict.count(word) != 0) return true;
                else return false;
            }
            
            /*if(existingWords.size() > 1) return false;
            else
            {
                auto it = existingWords.begin();
                if(*it == word) return true; 
                else return false;
            }*/
            
            /*int n = existingWords.size();
            for(int i=0; i<n; i++)
            {
                if(existingWords[i] != word) return false;
            }
            
            return true;*/
		}
		return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

/*
good test case-
["ValidWordAbbr","isUnique"]
[[["a","a"]],["a"]]
*/

