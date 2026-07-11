class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;

        for(int i=0;i<nums.size();i++)
        {
            int want=target-nums[i];
            if(mpp.find(want)!=mpp.end())
            {
                return { mpp[want],i};
            }
            mpp[nums[i]]=i;
        }
        return{-1,-1};
    }
};