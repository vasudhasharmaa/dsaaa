class Solution {
public:
    bool canShip(vector<int>& weights, int mid, int days) {
        int maxi = 0;
        int day = 1;
        for (int i = 0; i < weights.size(); i++) {

            maxi += weights[i];
            if (maxi > mid) {
                maxi = weights[i];
                day++;

                if (day > days)
                 {
                    return false;
                }
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, mid, days)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};