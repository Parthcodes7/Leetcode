class Solution {
public:
    int findDays(vector<int> &weights, int cap){
        int n = weights.size();
        int days = 1, load = 0;
        for(int i = 0; i < n; i++){
            if(weights[i] + load > cap){
                days += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            int numberofDays = findDays(weights, mid);
            if (numberofDays <= days) {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};