class Solution {
public:
    bool isPalindrome(string s) {
        return check(0, s.length() - 1, s);
    }

private:
    bool check(int left, int right, string &s) {

      
        if (left >= right) {
            return true;
        }

        if (!isalnum(s[left])) {
            return check(left + 1, right, s);
        }


        if (!isalnum(s[right])) {
            return check(left, right - 1, s);
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        return check(left + 1, right - 1, s);
    }
};