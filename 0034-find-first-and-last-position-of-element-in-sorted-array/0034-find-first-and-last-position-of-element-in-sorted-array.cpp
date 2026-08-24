class Solution {
public:
    int findFirst(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int first = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target == nums[mid]) {
                first = mid;
                end = mid - 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return first;
    }

    int findLast(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int last = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                last = mid;
                start = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};