class Solution {
public:
    int lengthLongestPath(string input) {
		vector<int> tabPosition;
		tabPosition.push_back(0);

		string currPath;
		int currLength = 0, longestLength = 0, n = input.length(), i = 0, numOfTabs = 0;
        
		while(i<n)
		{
			while(i<n && input[i] != '\n' && input[i] != '\t' && input[i] != '.')
            {
                //cout<<i<<" "<<input[i]<<endl;
                currPath += input[i];
                currLength++;
                i++;
            }
            if(i >= n) break;
            //cout<<i<<" "<<currPath<<" "<<currLength<<endl;
            
            if(input[i] == '.')
            {
                while(i<n && input[i] != '\n' && input[i] != '\t')
                {
                    currPath += input[i]; //includes appending '.'
                    currLength++;
                    
                    i++;
                }
                
                //cout<<"file found "<<currPath<<" "<<currLength<<" "<<i<<endl;
                
                if(longestLength < currLength) longestLength = currLength;
                if(i >= n) break;
            }
            
            if(input[i] == '\n')
            {
                i++; //for \t
                int numOfCurrTabs = 0;
                while(i<n && input[i] == '\t')
                {
                    numOfCurrTabs++;
                    i++;
                }
                
                //cout<<"tabs "<<numOfCurrTabs<<" "<<numOfTabs<<endl;
                
                if(numOfTabs < numOfCurrTabs) //append to current
                {
                    numOfTabs = numOfCurrTabs;
                    currPath += '\\';
                    currLength++;
                    
                    //update tab array
                    if(tabPosition.size()-1 < numOfCurrTabs) tabPosition.push_back(currLength);
                    else tabPosition[numOfCurrTabs] = currLength;
                    //as next position=currLength and that's where next word will go
                }
                else if(numOfTabs >= numOfCurrTabs) //current is equal or less: erase till tab position,then append
                {
                    numOfTabs = numOfCurrTabs;
                    while(tabPosition.size()-1 > numOfCurrTabs) tabPosition.pop_back(); //remove extra tabs positions
                    int nextPos = tabPosition[numOfCurrTabs];
                    currPath.erase(nextPos); //deletes everything from nextPos onwards
                    //cout<<"after erasing "<<currPath<<" "<<nextPos<<endl;
                    currLength = nextPos;
                }
                    
            }
            
		}

        return longestLength;
    }
};

