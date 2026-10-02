#include <stack>
#include <string>

using namespace std;

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

            if (ch == ')' && topBracket != '(') return false;
            if (ch == '}' && topBracket != '{') return false;
            if (ch == ']' && topBracket != '[') return false;

            st.pop();
        }

        
        return st.empty();
    }
};