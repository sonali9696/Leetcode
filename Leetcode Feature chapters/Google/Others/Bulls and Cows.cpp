//"3145","1112" -> Expected answer: "1A0B" -> 1 bull, 0 cow
//means it is a cow if the occurrence in the actual number is not already defined as a bull/cow
//"3145","1012" -> "0A1B" means since 1 is guessed twice but occurs only once so only 1 cow.

class Solution {
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
        
        /*for(int i=0; i<10; i++)
        {
            vector<int> temp = digitsToPos[i];
            vector<int>::iterator it2;
            cout<<"*******\n"<<i<<endl<<"-------\n";
            for(it2 = temp.begin(); it2 != temp.end(); it2++)
            {
                cout<<*it2<<" ";
            }
            cout<<endl;
        }*/
        
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
};