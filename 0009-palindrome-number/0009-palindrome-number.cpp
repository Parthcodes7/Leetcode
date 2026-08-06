class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long rev_no = 0;
        int dup = x;

        while(x>0){
            int ld = x%10;
            rev_no = rev_no*10 + ld;
            x /= 10;
        }
        return dup == rev_no;
    }
};