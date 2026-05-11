class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int left = -1;
        int right = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                left = mid;
                right = mid;
                while (left > 0&&nums[left] == nums[left - 1]) {
                    left--;
                }
                while (right <= n - 2&&nums[right] == nums[right + 1] ) {
                    right++;
                }
                break;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {left, right};
    }
};