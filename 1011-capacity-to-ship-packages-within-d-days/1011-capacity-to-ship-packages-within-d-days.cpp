class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int low = *std::max_element(weights.begin(), weights.end());
        int high = std::accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int requiredDays = 1;
            int currentLoad = 0;
            for (int w : weights) {
                if (currentLoad + w > mid) {
                    requiredDays++;
                    currentLoad = w;
                } else {
                    currentLoad += w;
                }
            }

            if (requiredDays <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};