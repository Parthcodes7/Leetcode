class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string st = "";
        for(int i = 0;i<n;i++){
            while(!st.empty() && k>0 && st.back()>num[i]){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }
        int i = 0;
        while(i<st.length() && st[i]=='0'){
            i++;
        }
        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }
};