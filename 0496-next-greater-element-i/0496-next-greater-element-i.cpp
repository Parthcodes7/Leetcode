#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int maxVal = 0;
        for (int num : nums2) {
            if (num > maxVal) maxVal = num;
        }

        vector<int> nge(maxVal + 1, -1);
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nge[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(nge[x]);
        }

        return ans;
    }
};