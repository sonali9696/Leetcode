class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> numbers; //does it matter too much if duplicates present?
        int pos = 0, hour = 0, minute = 0;
        for(int i = 0; i<2; i++) 
        {
            hour = hour*10 + (time[pos] - '0');
            numbers.push_back(time[pos]- '0');
            pos++;
        }
        pos++; //to skip ‘:’
        for(int i=0; i<2; i++) 
        {
            minute = minute*10 + (time[pos] - '0');
            numbers.push_back(time[pos]- '0');
            pos++;
        }

        int n = numbers.size();
        sort(numbers.begin(), numbers.end());
        
        //if needed, erase duplicates
        set<int> s;
        for(int i=0; i<n; i++) s.insert(numbers[i]);
        numbers.assign(s.begin(), s.end());
        n = numbers.size();
        
        int found = 0, currentNum;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                currentNum = numbers[i]*10 + numbers[j];
                if(currentNum > 59) break;
                if(currentNum <= minute) continue;
                else
                {
                    found = 1;
                    minute = currentNum;
                    break;
                }
            }
            if(currentNum > 59 || found == 1) break;
        }
        string ans;

        
        if(found != 1)
        {
            found = 0;
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<n; j++)
                {
                    currentNum = numbers[i]*10 + numbers[j];
                    if(currentNum > 23) break;
                    if(currentNum <= hour) continue;
                    else
                    {
                        found = 1;
                        hour = currentNum;
                        break;
                    }
                }
                if(currentNum > 23|| found == 1) break;
            }


            //if found = 1, minute formed by smallest digit
            minute = numbers[0]*10 + numbers[0];
            if(found != 1) hour = minute;
            //else all digits from smallest digit
        }
        

        string minString = to_string(minute);
        string hourString = to_string(hour);
        
        if(minute < 10) minString = '0' + minString;
        if(hour < 10) hourString = '0' + hourString;
        
        ans = hourString + ':' + minString;
        return ans;
    }

};