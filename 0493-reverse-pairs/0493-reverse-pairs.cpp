class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        int cnt = 0;

        for (int j = 0; j < n; j++) {
            long long target = 2LL * nums[j] + 1;
            auto it = lower_bound(sorted.begin(), sorted.end(), target);
            cnt += (sorted.end() - it);

            sorted.insert(lower_bound(sorted.begin(), sorted.end(), nums[j]), nums[j]);
        }

        return cnt;
    }

    int team(vector<int>& skill, int n) {
        return reversePairs(skill);
    }
};