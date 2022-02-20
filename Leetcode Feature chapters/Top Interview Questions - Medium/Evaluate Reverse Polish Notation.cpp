class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //keep adding numbers to stack
        //if you get an operator, pop 2 numbers, latest being 2nd operand
        //evaluate operator on it and push the result
        
        int n = tokens.size();
        stack<int> s;
        vector<string> operators = {"+","-","*","/"};
        for(int i=0; i<n; i++)
        {
            //it is a number
            if(find(operators.begin(), operators.end(), tokens[i]) == operators.end())
            {
                s.push(stoi(tokens[i]));
            }
            else //operator
            {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                
                if(tokens[i] == "+") s.push(op1 + op2);
                else if(tokens[i] == "-") s.push(op1 - op2);
                else if(tokens[i] == "*") s.push(op1 * op2);
                else s.push(op1 / op2);
            }
        }
        
        return s.top();
    }
};