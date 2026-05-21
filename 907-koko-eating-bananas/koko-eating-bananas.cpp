class Solution {
public:

long long totalhrs(vector<int>& piles,int k)
        {
            long long hrs=0;
            for(int i=0;i<piles.size(); i++)
            {
                hrs+=(piles[i]+k-1)/k;
            }
            
            return hrs;
        }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(totalhrs(piles,mid)<=h)
            {
                high=mid-1;
                
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};