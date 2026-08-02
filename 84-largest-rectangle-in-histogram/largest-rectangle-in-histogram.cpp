class Solution {
public:
vector<int>findnse(vector<int>&heights)
{
    stack<int>st;
    vector<int>nse(heights.size());
    int n=heights.size();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&heights[st.top()]>heights[i])
        {
            st.pop();
        }
        if(st.empty())nse[i]=n;
        else nse[i]=st.top();
        st.push(i);
    }
    return nse;
}
vector<int>findpse(vector<int>&heights)
{
    stack<int>st;
    vector<int>pse(heights.size());
    int n=heights.size();
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(st.empty())pse[i]=-1;
        else pse[i]=st.top();
        st.push(i);
    }
    return pse;
}
    int largestRectangleArea(vector<int>& heights) {

        vector<int>next=findnse(heights);
        vector<int>prev=findpse(heights);
        int area=0;
        int maxarea=0;
        for(int i=0;i<heights.size();i++)
        {
            

            area=heights[i]*(next[i]-prev[i]-1);
            maxarea=max(maxarea,area);
        }
        return maxarea;
        
    }
};