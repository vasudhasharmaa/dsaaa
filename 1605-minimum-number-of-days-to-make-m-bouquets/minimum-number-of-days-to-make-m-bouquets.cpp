class Solution {
public:
    bool canMake(vector<int>& bloomDay, int mid, int m, int k) {
        int count = 0;
        int bouquet = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;

                if (count == k) {
                    bouquet++;

                    count = 0;
                    if (bouquet >= m) {
                        return true;
                    }
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
    

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if((long long) m*k>bloomDay.size()) return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay,mid,m,k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};