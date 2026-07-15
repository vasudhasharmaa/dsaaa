class Solution {
public:

int calc(int idx,vector<int>&nums,vector<int>&dp)
{
    if(idx==0)return nums[0];
    if(idx<0)return 0;
    if(dp[idx]!=-1)return dp[idx];//ans

    int pick=nums[idx]+ calc(idx-2,nums,dp);
    int nopick=0+calc(idx-1,nums,dp);
    return dp[idx]=max(pick,nopick);
}
int rob(vector<int>& nums) {
    vector<int>dp(nums.size(),-1);
    
    return calc(nums.size()-1,nums,dp);
        
    }
};