class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            if (st.empty()) {
                return false;
            }
            
            char topBracket = st.top();
            if ((ch == ')' && topBracket == '(') ||
                (ch == '}' && topBracket == '{') ||
                (ch == ']' && topBracket == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
        
        return st.empty();
    }
};