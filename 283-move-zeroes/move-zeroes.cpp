class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      
        int i = 0;
        int count=0;
        int n=nums.size();
        while (i < nums.size()) {
            if(count==n) break;
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                
            }else{
                i++;
            }
            count++;
            
        }
    }
};