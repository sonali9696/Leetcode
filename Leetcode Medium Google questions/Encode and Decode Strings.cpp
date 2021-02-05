//we take delimiter as say #
//but since string can have any ascii character including #
//we store (length of the string + # + string)
//this will ensure that the first # is not part of string, and length given will determine where the string starts and finishes

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        int n = strs.size();
        for(int i=0; i<n; i++)
        {
            int len = strs[i].size();
            encoded += (to_string(len) + '#' + strs[i]);
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int l = s.length();
        int i=0;
        while(i<l)
        {
            string count = "";
            while(i<l && s[i] != '#')
            {
                count += s[i];
                i++;
            }
            
            if(i >= l) break;
            
            i++; //to get character after #
            int len = stoi(count);
            string currStr = s.substr(i,len);
            ans.push_back(currStr);
            i += len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));