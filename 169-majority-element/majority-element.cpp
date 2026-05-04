class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int maxFreq=0;
        for(auto it:mpp)
        {
            if(it.second>maxFreq)
            {
                maxFreq=it.second;
                ans=it.first;
               
            }
        }
        return ans;
    }
};