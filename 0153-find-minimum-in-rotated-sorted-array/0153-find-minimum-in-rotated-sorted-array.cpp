class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            
            if (nums[low] <= nums[high]) {
                ans = std::min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                ans = std::min(ans, nums[low]);
                low = mid + 1;
            } 
            
            else {
                ans = std::min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};