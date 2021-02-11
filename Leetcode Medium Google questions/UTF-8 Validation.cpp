class Solution {
public:
	bool validUtf8(vector<int>& data)
	{
		int n = data.size();
		int i=0;
		while(i<n)
		{
			if((data[i] >> 7) == 0b0) 
            {
                i++;
                continue;
            }
			else
			{
				int numOfBytes;
				if((data[i] >> 6) == 0b10) return false; //1 byte not starting with 0
				else if((data[i] >> 5) == 0b110) numOfBytes = 2;
				else if((data[i] >> 4) == 0b1110) numOfBytes = 3;
				else if((data[i] >> 3) == 0b11110) numOfBytes = 4;
				else return false; //bytes > 4
				
				i++; //see next byte
                numOfBytes--; //bytes remaining
				while(numOfBytes--) //rest n-1 should have 10
				{
					if(i >= n) return false; //less bytes than expected
					if((data[i] >> 6) != 0b10) return false;
					i++;
				}
			}
		}
		return true;
    }
};



/*class Solution {
public:
	string numberToBinary(int num)
	{
		string ans = "";
		int count = 0;
		while(count < 8 && num != 0)
		{
			int temp = num % 2;
			num /= 2;
			ans += to_string(temp);
			count++;
		}
        if(ans.size() < 8)
        {
            int remainingSize = 8-ans.size();
            for(int i=1; i<=remainingSize; i++) ans.push_back('0');
        }
		reverse(ans.begin(), ans.end());
        
        return ans;
	}

    bool validUtf8(vector<int>& data) {
       	//convert integers to binary
		vector<string> dataInBinary;
		int n = data.size();
		int i=0;
		while(i<n)
		{
			string curr = numberToBinary(data[i]);
			if(curr[0] == '0') 
            {
                i++;
                continue;
            }
			else
			{
				int j = 0, numberOfBytes = 0;
				while(j<8 && curr[j] == '1')
				{
					numberOfBytes++;
					j++;
				}
				if(numberOfBytes > 4) return false; //covers case where no 0 after all 1s
				else if(numberOfBytes == 1) return false; //should start with 0
                else
				{
					numberOfBytes--; //current byte counted
					int remainingBytes = n - i - 1;
					if(remainingBytes < numberOfBytes) return false; //lesser bytes present than expected
					int count = 1;
					i++;
                    while(i < n && count <= numberOfBytes)
                    {
                        curr = numberToBinary(data[i]);
                        if(curr[0] == '1' && curr[1] == '0') 
                        {
                            i++;
                            count++;
                            continue;
                        }
                        else return false;
                    }
				}
			}
		}

		return true;
			
    }
};*/

