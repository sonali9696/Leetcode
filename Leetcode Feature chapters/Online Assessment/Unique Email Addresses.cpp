class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        vector<string> domainNames, localNames; //local, domain name
        
        int n = emails.size();
        string curr_email, localName, domainName;
        
        for(int i=0; i<n; i++)
        {
            curr_email = emails[i];
            //cout<<"curr_email="<<curr_email<<endl;
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
            
            //cout<<"index="<<index;
            //cout<<"localName="<<localName<<endl;
            //cout<<"domainName="<<domainName<<endl;
            
            if(find(localNames.begin(), localNames.end(), localName) == localNames.end()) //new local name
            {
                localNames.push_back(localName);
                domainNames.push_back(domainName);
            }
            else
            {
                //check if different domain name
                int n2 = localNames.size();
                int found = 0;
                for (int i=0; i<n2; i++)
                {
                    if(localNames[i] == localName)
                    {
                        if(domainNames[i] == domainName) 
                        {
                            found = 1; //duplicate
                            break;
                        }
                    }
                }
                
                if(found != 1)
                {
                    localNames.push_back(localName);
                    domainNames.push_back(domainName);
                }
                
            }
            
            
        }
        
        return localNames.size();
        
    }
};