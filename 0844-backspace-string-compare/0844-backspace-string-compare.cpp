class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
private:
    string build(string str){
        string st = "";
        for(char c: str){
            if(c != '#'){
                st.push_back(c);
            }
            else if(!st.empty()){
                st.pop_back();
            }
        }
        return st;
    }

};