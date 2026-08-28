class Solution {
public:
    long long calculaTetotalHours(vector<int>& piles, int speed) {
        long long totalH = 0;
        for (int banana : piles) {
            totalH += ceil((double)banana / speed);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPiles = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxPiles;
        int ans = maxPiles;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = calculaTetotalHours(piles, mid);

            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};