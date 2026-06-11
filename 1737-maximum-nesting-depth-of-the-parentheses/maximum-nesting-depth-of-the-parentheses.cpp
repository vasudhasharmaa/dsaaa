class Solution {
public:
    int maxDepth(string s) {
        int maxlen=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                count++;
                maxlen=max(maxlen,count);
                
            }
            if(s[i]==')')
            {
                count--;
            }
            
        }
        return maxlen;
    }
};