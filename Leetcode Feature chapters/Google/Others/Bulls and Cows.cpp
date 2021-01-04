//"3145","1112" -> Expected answer: "1A0B" -> 1 bull, 0 cow
//means it is a cow if the occurrence in the actual number is not already defined as a bull/cow
//"3145","1012" -> "0A1B" means since 1 is guessed twice but occurs only once so only 1 cow.


//"3145","1112" -> Expected answer: "1A0B" -> 1 bull, 0 cow
//means it is a cow if the occurrence in the actual number is not already defined as a bull/cow
//"3145","1012" -> "0A1B" means since 1 is guessed twice but occurs only once so only 1 cow.

//"3145","1112" -> Expected answer: "1A0B" -> 1 bull, 0 cow
//means it is a cow if the occurrence in the actual number is not already defined as a bull/cow
//"3145","1012" -> "0A1B" means since 1 is guessed twice but occurs only once so only 1 cow.


class Solution {
public:
    string getHint(string secret, string guess) {
        
        int freq[10], l = secret.size(), bulls=0, cows=0;
        memset(freq,0,sizeof(freq));
        
        for(int i=0; i<l; i++)
        {
            int s = secret[i] - '0', g = guess[i] - '0';
            if(s == g) bulls++;
            else
            {
                if(freq[g] > 0)//more occurrences of g in secret than guess
                    cows++; //g mapped to old occurrence in secret
                if(freq[s] < 0) //current char of secret can be mapped to old occurrence in guess as cow
                    cows++;
            }
            freq[s]++;
            freq[g]--; //secret gives +ve contribution for freq, guess gives -ve
        }
        
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};

/*class Solution {
public:
    string getHint(string secret, string guess) {
        
        int l = secret.length();
        map<int,int> freqOfDigits; //digits 0 to 9 mapped to number of occurrences
        for(int i=0; i<l; i++) 
        {
            int n = secret[i]-'0';
            if(freqOfDigits.find(n) == freqOfDigits.end()) freqOfDigits[n] = 1;
            else freqOfDigits[n]++;
        }
        
        int bulls = 0;
        vector<int> positions;
        for(int i=0; i<l; i++) 
        {
            if(secret[i] == guess[i])
            {
                bulls++;
                freqOfDigits[secret[i]-'0']--;
                positions.push_back(i);
            } 
            //cant see cows in this pass as "2031" "1031" here the 1st "1" cant be a cow as the 1 in the secret will be a bull in the future   
        }
        
        int cows = 0;
        int index=0;
        for(int i=0; i<l; i++)
        { 
            if(index < positions.size() && positions[index] == i) //already a bull
            {
                index++;
                continue;
            }
            int n = guess[i]-'0';
            
            if(freqOfDigits.find(n) == freqOfDigits.end() || freqOfDigits[n] < 1) continue;
            else 
            {
                cows++;
                freqOfDigits[n]--;
            }
        }
        
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};*/
/*class Solution {
public:
    string getHint(string secret, string guess) {
        //map of digits mapped to positions
        //gets bulls first and remove those positions
        //next iteration see if positions still exist for those numbers -> get cows
        
        int l = secret.length();
        vector<vector<int>> digitsToPos(10); //digits 0 to 9 mapped to positions
        for(int i=0; i<l; i++) digitsToPos[(secret[i]-'0')].push_back(i);
        
        int bulls = 0;
        map<int,int> bullPos;
        for(int i=0; i<l; i++) 
        {
            if(secret[i] == guess[i])
            {
                bullPos[i] = 1;
                bulls++;
                int n = secret[i]-'0';
                vector<int>::iterator it = find(digitsToPos[n].begin(),digitsToPos[n].end(),i);
                digitsToPos[n].erase(it);
                //cout<<"erasing "<<i<<" where n="<<n<<endl;
            }
        }
        
        
        int cows = 0;
        for(int i=0; i<l; i++)
        {
            if(bullPos.find(i) != bullPos.end()) continue; //already a bull pos
            
            int n = guess[i]-'0';
            
            if(digitsToPos[n].size() == 0) continue;
            else 
            {
                cows++;
                digitsToPos[n].pop_back();
            }
        }
        
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};*/