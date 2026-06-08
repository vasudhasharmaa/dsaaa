class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0;
        int n = s.size();
        bool ans = false;
        for(int i=0;i<n;i++) {
            char first=s[0];
            s.erase(0, 1);
            s.push_back(first);
            
            if (s == goal) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};