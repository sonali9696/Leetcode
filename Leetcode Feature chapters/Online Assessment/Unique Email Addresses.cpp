class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        vector <string> EmailAddresses;
        
        int n = emails.size();
        string curr_email, localName, domainName;
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            curr_email = emails[i];
            localName = "", domainName = "";
            
            //extract local and domain name
            int index = 0;
            char c = curr_email[index];;
            
            while(c != '@')
            {
                if(c == '.') 
                {
                    index++;
                }
                else if(c == '+')
                {
                    while(c != '@') 
                    {
                        index++;
                        c = curr_email[index];
                    }
                    
                    break;
                }
                else
                {
                    localName = localName + c;   
                    index++;
                }
                
                c = curr_email[index];
            }
            
            index++; //cursor at domainName
            int n3 = curr_email.length();
            domainName = curr_email.substr(index, n3-index);
            
            string email = localName + '@' + domainName;
            if(find(EmailAddresses.begin(),EmailAddresses.end(),email) == EmailAddresses.end()) //new email
            {
                EmailAddresses.push_back(email);
            }
            
        }
        
        return EmailAddresses.size();
        
    }
};