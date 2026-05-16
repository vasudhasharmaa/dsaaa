class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int smallest=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
          
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<smallest)
                {
                    smallest=nums[low];
                }
                low=mid+1;
            }
            else
            {
                low++;
                high--;
            }
            
        }
        return smallest;
    }
};