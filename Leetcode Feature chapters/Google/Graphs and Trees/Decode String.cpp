class Solution {
public:
    string decodeString(string s) {
        int l = s.length();
        stack<string> st;
        stack<int> freq;
	    string decodedString = "";
        
        string temp = "";
        for(int i=0; i<l; i++)
        {
            int num = 0;
            while(i < l && s[i] >= '0' && s[i] <= '9')
            {
                num = num*10 + (s[i] - '0');
                i++;
            }
            if(num != 0) 
            {
                freq.push(num);
            }
            
            if(s[i] == '[') 
            {
                temp = "";
                temp.push_back(s[i]); 
                st.push(temp);
                temp = "";
            }
            
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) //can't have spcl characters
            {
                if(st.empty() || st.top() == "[")
                {
                    temp = "";
                    temp.push_back(s[i]); 
                    st.push(temp);
                    temp = "";
                }
                else
                {
                    st.top() = st.top() + s[i];
                }
            }
            
            if(s[i] == ']')
            {
                int numOfRepetitions = freq.top();
                freq.pop();
		
		        string curr_string = "";
			    while(st.top() != "[")
                {
                    curr_string = st.top() + curr_string;
                    st.pop();
                }

                st.pop(); //removing [
                for(int j = 0; j < numOfRepetitions; j++)
                    st.push(curr_string);
            }
        }
        while(!st.empty())
		{
			decodedString = st.top() + decodedString;
			st.pop();
		}
        
        return decodedString;
    }
};

