class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n == 0)
            return true;

        stack<char>st;
        for(char &ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else {
                if(!st.empty()){
                    if(ch == ')' && st.top() == '(')
                        st.pop();  
                    else if(ch == '}' && st.top() == '{')
                        st.pop();
                    else if(ch == ']' && st.top() == '[')
                        st.pop();
                    else{
                        return false;
                    }
                }
                else
                    return false;
            }
        }

        return st.empty();
    }
};
