class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {

        string ans = S;
        int stringLen = S.length();
        int n = indexes.size();
        map<int,int> indexMapping; //between S and ans
        
        for(int i=0; i<stringLen; i++) indexMapping[i] = i;
        
        for(int i = 0; i<n; i++)
        {
            //cout<<"Before ans="<<ans<<endl;
            int pos = indexes[i];
            string sourceInString = S.substr(pos,sources[i].length());
            int currPos = indexMapping[pos];
            if((sourceInString.compare(sources[i])) == 0)
            {
                if(currPos == 0) ans = targets[i] + ans.substr(currPos+sources[i].length());
                else if(currPos + sources[i].length() > ans.length()-1) 
                    ans = ans.substr(0,currPos) + targets[i];
                else ans = ans.substr(0,currPos) + targets[i] + ans.substr(currPos+sources[i].length());
                
                for(int j = pos; j < stringLen; j++) //j = pos not pos+1 for empty sources case
                    indexMapping[j] = indexMapping[j] + targets[i].length() - sources[i].length();
                
            } 
            //cout<<"After ans="<<ans<<endl;
        }

        return ans;

    }

    
};