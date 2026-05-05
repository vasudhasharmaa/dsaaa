class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int minSo=INT_MAX;
        int profit=0;
        int buy=INT_MAX;
        int maxProf=0;
        for(int i=0;i<prices.size();i++)
        {
            
            if(prices[i]<minSo)
            {
                minSo=prices[i];
                buy=min(buy,minSo);
            
            
            }
            profit=prices[i]-buy;
            maxProf=max(maxProf,profit);
        }
        return maxProf;
       

    }
};