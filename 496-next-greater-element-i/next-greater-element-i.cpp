class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        int m=nums2.size();
        vector<int>ans(m);
        for(int i=m-1;i>=0;i--)
        {
            while(!st.empty()&&nums2[i]>st.top())st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<m;i++)
        {
            mp[nums2[i]]=ans[i];
        }
        vector<int>fans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            fans[i]=mp[nums1[i]];
        }

        return fans;
    }
};