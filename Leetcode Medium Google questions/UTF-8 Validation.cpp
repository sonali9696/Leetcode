class Solution {
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
		for(int i=0; i<n; i++)
		{
			string b = numberToBinary(data[i]);
			dataInBinary.push_back(b);
            cout<<"push "<<b<<endl;
		}
 		
		int i=0;
		while(i<n)
		{
			string curr = dataInBinary[i];
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
                        curr = dataInBinary[i];
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
};



