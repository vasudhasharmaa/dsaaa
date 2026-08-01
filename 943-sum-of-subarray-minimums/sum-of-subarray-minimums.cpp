class Solution {
public:
    vector<int>findnse(vector<int>&arr)
    {
        stack<int>st;
        vector<int>nse(arr.size());
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty()&&arr[i]<arr[st.top()])st.pop();
            if(st.empty())nse[i]=arr.size();
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findpse(vector<int>&arr)
    {
        stack<int>st;
        vector<int>pse(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty()&&arr[i]<=arr[st.top()])st.pop();
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
         vector<int> next = 
            findnse(arr);
        
        vector<int> prev =
            findpse(arr);
       
        long long sum=0;
        int mod=1e9 + 7;
        for(int i=0;i<arr.size();i++)
        {
            long long right=next[i]-i;
            long long left=i-prev[i];
            sum=(sum+(right*left*1LL%mod)*arr[i])%mod;
        }
        return sum;
    }
};