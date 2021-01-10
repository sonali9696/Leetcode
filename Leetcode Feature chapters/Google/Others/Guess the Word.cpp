/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

//guess a word
//suppose it has 2 matches
//we find all words from word list which has exactly 2 common chars with our guessed word
//so that we can get other 4 letters different to get the secret
//suppose new word has 3 matches then we find other words with 3 common chars and check them so on

//For selecting which word to guess out of the pool of same number of matches-
//make 6 groups of matches with possible guessed word - 0 to 6 matches
//see which is the largest group in these 6
//find a guess among possible words, such that this largest group is the smallest
//i.e. the distribution of matched words are well distributed so that the possible words set gets smaller and smaller


//Minmax - guessing word as described above
//in below it is assumed that largest group for each is with 0 matches
//this is true by probability - https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison


/* runtime beats 49% solutions

class Solution {
public:
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == b[i])
                matches ++;
        return matches;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            unordered_map<string, int> count;
            for (string w1 : wordlist)
                for (string w2 : wordlist)
                    if (match(w1, w2) == 0)
                        count[w1]++;
            pair<string, int> minimax = {wordlist[0], 1000};
            for (string w : wordlist)
                if (count[w] <= minimax.second)
                    minimax = make_pair(w, count[w]);
            x = master.guess(minimax.first);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(minimax.first, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }
};*/



//Guessing random word - runtime beats 100%

class Solution {
public:
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == b[i])
                matches ++;
        return matches;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            string guess = wordlist[rand() % (wordlist.size())]; //guess random word
            x = master.guess(guess);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(guess, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }

};

