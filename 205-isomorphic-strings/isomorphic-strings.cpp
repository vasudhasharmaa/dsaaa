class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,char>mp;
        set<char>used;

        for(int i=0;i<s.size();i++)
        {
            char original=s[i];
            char replacement=t[i];

            if(mp.find(original)==mp.end())
            {
                if(used.find(replacement)!=used.end())
                {
                    return false;
                }
                mp[original]=replacement;
                used.insert(replacement);
            }
            else
            {
                if(mp[original]!=replacement)
                {
                    return false;
                }
            }
        }
        return true;
    }
};