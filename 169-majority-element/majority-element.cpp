class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int votes = 1;

        for (int i = 1; i <= nums.size() - 1; i++) {
            if (nums.size() == 1)
                return 1;
            if (candidate == nums[i]) {
                votes++;
            }

            else if (candidate != nums[i]) {
                votes--;
                if (votes == 0) {
                    candidate = nums[i];
                    votes=1;
                }
            }
        }
        return candidate;
    }
};