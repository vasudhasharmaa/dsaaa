class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid;
        for(int i=0;i<n;i++)
        {
            while(low<=high)
            {
                mid=(low+high)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]<target) low=mid+1;
                
                else high=mid-1;

            }
            return low;
            
            
        }
        return mid;
    }
};