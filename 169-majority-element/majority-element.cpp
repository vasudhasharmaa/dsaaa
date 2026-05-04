class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate =nums[0];
        int count=1;
        int n=nums.size();

        for(int i=1;i<n;i++)
        {
            if(candidate==nums[i])
            {
                count++;
            }
            if(candidate!=nums[i])
            {
                count--;
            }
            if(count==0)
            {
                candidate=nums[i+1];
            }
        }
        return candidate;
    }
};