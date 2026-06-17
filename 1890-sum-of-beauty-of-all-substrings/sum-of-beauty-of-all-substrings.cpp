class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int beauty = 0;

        for (int i = 0; i < s.size(); i++) {
                int freq[26] = {0};
            for (int j = i; j < s.size(); j++) {
               
                int mx = 0; // current max in substr
                int mn = INT_MAX; // current min in substr
                

                freq[s[j]-'a']++;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        mx = max(mx, freq[k]);
                        mn = min(mn, freq[k]);
                    }
                }

                beauty = mx - mn;
                sum += beauty;
            }
        }
        return sum;
    }
};