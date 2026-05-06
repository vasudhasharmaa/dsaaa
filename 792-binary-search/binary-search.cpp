class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        for(int i=0;i<n;i++)
        {
            while(low<=high)
            {
                mid=(high+low)/2;
                if(nums[mid]==target) return mid;
                else if(target>nums[mid])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            return -1;
        }
        return mid;
        
    }
};