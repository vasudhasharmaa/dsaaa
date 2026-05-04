class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int>temp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                if((nums[i]+nums[j])==target)
                {
                    temp.push_back(i);
                    temp.push_back(j);
                }
            }
        }
        return temp;
      
      }  
};