class Solution {
public:
    bool backspaceCompare(string S, string T) {
		//int len_S = S.length(), len_T = T.length();
        //not fixing it as length will keep changing due to backspace

		for(int i=0; i<S.length(); i++)
		{
			if(S[i] == '#') 
            {
                S.erase(i,1); //to remove hash
                i--; //so that i++ gets it back here
                if(!S.empty() && i >= 0) 
                {
                    S.erase(i,1); //to remove character
                    i--;
                }
            }
            //can’t do S.length() as empty for cases like ##c
		}

		for(int i=0; i<T.length(); i++)
		{
			if(T[i] == '#') 
            {
                T.erase(i,1); 
                i--;
                if(!T.empty() && i >= 0) 
                {
                    T.erase(i,1); 
                    i--;
                }
            }
		}

		if(S.compare(T) == 0) return true;
		else return false;
    }

};