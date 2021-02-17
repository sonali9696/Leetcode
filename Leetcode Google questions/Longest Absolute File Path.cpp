//good test case - "file1.txt\nfile2.txt\nlongfile.txt"

class Solution{
public:
	int lengthLongestPath(string input){
		stringstream ss(input);
        string data;
        int maxPathLength = 0;
        
		unordered_map<int,int> lengthAtEachDepth; //tab count(depth), length till that depth
		lengthAtEachDepth[0] = 0;

        while(getline(ss,data,'\n'))
        {
            int i = 0;
            while(data[i] == '\t') i++;
            string name;
            int len = 0, numOfTabs = i; //if index = 2 right after tabs means “\t\t” i.e. 2 tabs
            //above cover if #tabs = 0
            if(i == 0) //root directory 
            {
                name = data;
                lengthAtEachDepth[0] = name.size();
            }
            else
            {
                name = data.substr(i); //from the index after last \t to end
                lengthAtEachDepth[numOfTabs] = lengthAtEachDepth[numOfTabs-1] + 1 + name.size();
                //+1 is for the \ before we would append the name to the path
            }
        
            if(name.find('.') != string::npos) //file exists
            {
                if(lengthAtEachDepth[numOfTabs] > maxPathLength) maxPathLength = lengthAtEachDepth[numOfTabs];
            }
        }	
		
		return maxPathLength;
    }
};


/*class Solution {
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
                currPath += input[i];
                currLength++;
                i++;
            }
            if(i >= n) break;
            
            if(input[i] == '.')
            {
                while(i<n && input[i] != '\n' && input[i] != '\t')
                {
                    currPath += input[i]; //includes appending '.'
                    currLength++;
                    i++;
                }
                
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
                    currLength = nextPos;
                }
                    
            }
            
		}

        return longestLength;
    }
};*/

