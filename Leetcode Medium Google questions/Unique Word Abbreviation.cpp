class ValidWordAbbr {
private:
	map<string,vector<string> > abbreviations;

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
       	int n = dictionary.size();
		for(int i=0; i<n; i++)
		{
			string abbr = abbreviate(dictionary[i]);
			abbreviations[abbr].push_back(dictionary[i]);
		}
    }
    
    bool isUnique(string word) {
		string abbr = abbreviate(word);
		if(abbreviations.find(abbr) == abbreviations.end()) return true;
		else
		{
			vector<string> existingWords = abbreviations[abbr];
			//if 2 words say deer,door have same abbreviation and word is deer then it is saying to return false maybe because of door so if 2 or more words have same abbr then not possible to check that condition so all words in vector has to be this word
            
            int n = existingWords.size();
            for(int i=0; i<n; i++)
            {
                if(existingWords[i] != word) return false;
            }
            
            return true;
		}
		return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

