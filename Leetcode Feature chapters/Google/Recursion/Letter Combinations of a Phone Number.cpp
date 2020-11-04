//map numbers to letters
//recurse such that each letter under the number is tried and recursed
//stop when reached length at end and add s to ans

class Solution {
private:
	map<char,vector<char>> numbersToLetters;
public:
    void createCombination(string digits, int index, string s, vector<string> &combos)
    {
        if(index == digits.length())
        {
            combos.push_back(s);
        }
        
        char currNum = digits[index];
        vector<char> letters = numbersToLetters[currNum];
        for(int i=0; i<letters.size(); i++)
        {
            s.push_back(letters[i]);
            createCombination(digits,index+1,s,combos);
            s.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> combos;
        if(digits.empty()) return combos;
        
        char letter = 'a';
        for(char i='2'; i<='9'; i++)
        {
            int numOfLetters = 3;
            if(i == '7' || i == '9') numOfLetters = 4; 
            
            for(int j=0; j<numOfLetters; j++)
            {
                numbersToLetters[i].push_back(letter);
                letter++;
            }
        }
        
        string s = "";
        createCombination(digits,0,s,combos);

        return combos;
    }
};

