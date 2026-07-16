class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1,temp2;
        if(n==1)return nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(rob2(temp1),rob2(temp2));
        
    }
    long long rob2(vector<int>&arr)
    {
        if(arr.size()==1)return arr[0];
        int prev2=arr[0];
        int curr=0;
        int prev = max(arr[0], arr[1]);
        for(int i=2;i<arr.size();i++)
        {
            int pick=arr[i]+prev2;
            int nopick=0+prev;

            curr=max(pick,nopick);
            prev2=prev;
            prev=curr;

        }
        return prev;
    }
};