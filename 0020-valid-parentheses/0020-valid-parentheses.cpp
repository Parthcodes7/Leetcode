#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }

            // If we encounter a closing bracket but the stack is empty
            if (st.empty()) {
                return false;
            }

            char topBracket = st.top();

            // Check if top bracket matches current closing bracket
            if (ch == ')' && topBracket != '(') return false;
            if (ch == '}' && topBracket != '{') return false;
            if (ch == ']' && topBracket != '[') return false;

            st.pop();
        }

        // Returns true if all brackets were properly matched and popped
        return st.empty();
    }
};