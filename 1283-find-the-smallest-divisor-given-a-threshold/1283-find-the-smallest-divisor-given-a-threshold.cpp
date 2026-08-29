class Solution {
public:
    int SumbyD(const std::vector<int>& nums, int div) {
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(std::vector<int>& nums, int threshold) {
        
        if (nums.size() > threshold) return -1;

        int low = 1;
        int high = *std::max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (SumbyD(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};