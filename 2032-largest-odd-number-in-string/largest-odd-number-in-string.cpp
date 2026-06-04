class Solution {
public:
    string largestOddNumber(string num) {
        
        int right=(int)num.size()-1;
        string ans="";
        if((int)num.size()==0) return"";
        for(int i=right;i>=0;i--)
        {
            if(((num[i]-'0')%2)!=0) 
            {
                ans=num.substr(0,i+1);
                break;

            }
            else if(((num[i]-'0')%2)==0)
            {
                continue;

         
            }
        
            
        }
        return ans;
    }
};