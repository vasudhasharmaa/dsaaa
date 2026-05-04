class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        int zero=mpp[0];
        int one=mpp[1];
        int two=mpp[2];

        for(int i=0;i<zero;i++)
        {
            nums[i]=0;
        }
        for(int i= zero;i<zero+one;i++)
        {
            nums[i]=1;
        }
        for(int i=zero+one;i<n;i++)
        {
            nums[i]=2;
        }
        
        return;
    }
};