class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1, high = n;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long coinsNeeded = mid * (mid + 1) / 2;

            if (coinsNeeded <= n) {
                ans = mid;         // Valid rows, try to find a larger number of rows
                low = mid + 1;
            } else {
                high = mid - 1;    // Too many coins needed, search lower
            }
        }

        return ans;
    }
};