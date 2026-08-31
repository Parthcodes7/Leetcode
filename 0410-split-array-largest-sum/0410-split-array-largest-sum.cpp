class Solution {
public:
    int countStudents(vector<int> &nums, int pages){
        int students = 1;
        long long pagesStudents = 0;
        for(int i = 0; i < nums.size(); i++){
            if(pagesStudents + nums[i] <= pages){
                pagesStudents += nums[i];
            }
            else{
                students += 1;
                pagesStudents = nums[i];
            }
        }
        return students;
    }

    int findPages(vector<int> &nums, int m) {
        int n = nums.size();
        if(m > n) return -1;
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int students = countStudents(nums, mid);

            if(students > m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, k);
    }
};