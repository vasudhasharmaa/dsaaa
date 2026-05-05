class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>temp1; // negative
        vector<int>temp2; //positive 
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] <0)
            {
                temp1.push_back(nums[i]);
            }
            else
            {
                temp2.push_back(nums[i]);
            }
        }
        vector<int>temp;
        int left=0;
        int right=0;

        while(left<temp1.size()&& right<temp2.size())
        {
            temp.push_back(temp2[right]);
            temp.push_back(temp1[left]);
            left++;
            right++;
        }
        while(right<temp2.size())
        {
            temp.push_back(temp2[right]);
        }
        while(left<temp1.size())
        {
            temp.push_back(temp1[left]);
        }
        return temp;
    }
};