class Solution {
public:
    int beautySum(string s) {
        int sum = 0;

      

        int beauty = 0;

        for (int i = 0; i < s.size(); i++) {

            for (int j = i; j < s.size(); j++) {
                int freq[26] = {0};
                int mx = 0; // current max in substr
                int mn = INT_MAX; // current min in substr
                string sub = s.substr(i, j - i + 1);
                for (char ch : sub) {
                    freq[ch - 'a']++;
                }

                for (int i = 0; i < 26; i++) {
                    if (freq[i] > 0) {
                        mx = max(mx, freq[i]);
                        mn = min(mn, freq[i]);
                    }
                }

                beauty = mx - mn;
                sum += beauty;
            }
        }
        return sum;
    }
};