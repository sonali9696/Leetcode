//"3145","1112" -> Expected answer: "1A0B" -> 1 bull, 0 cow
//means it is a cow if the occurrence in the actual number is not already defined as a bull/cow
//"3145","1012" -> "0A1B" means since 1 is guessed twice but occurs only once so only 1 cow.


//"3145","1112" -> Expected answer: "1A0B" -> 1 bull, 0 cow
//means it is a cow if the occurrence in the actual number is not already defined as a bull/cow
//"3145","1012" -> "0A1B" means since 1 is guessed twice but occurs only once so only 1 cow.

class Solution {
public:
    string getHint(string secret, string guess) {
        //count occurrence of digits
        //gets bulls first and remove one count of positions
        //next iteration see if positions still exist for those numbers -> get cows
        
        int l = secret.length();
        map<int,int> freqOfDigits; //digits 0 to 9 mapped to number of occurrences
        for(int i=0; i<l; i++) 
        {
            int n = secret[i]-'0';
            if(freqOfDigits.find(n) == freqOfDigits.end()) freqOfDigits[n] = 1;
            else freqOfDigits[n]++;
        }
        
        /*map<int,int>::iterator it;
        for(it = freqOfDigits.begin(); it != freqOfDigits.end(); it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }*/
        
        int bulls = 0;
        vector<int> positions;
        for(int i=0; i<l; i++) 
        {
            if(secret[i] == guess[i])
            {
                //cout<<i<<" is a bull"<<endl;
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
                //cout<<i<<" is a cow"<<endl;
                cows++;
                freqOfDigits[n]--;
            }
        }
        
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};

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