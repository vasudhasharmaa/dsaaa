class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            char next=s[i+1];
            if (mp.find(curr) != mp.end()) {
                if (mp[curr] < mp[next]) {
                    int diff = mp[next] - mp[curr];
                    sum += diff;
                    i++;
                } else {
                    sum += mp[curr];
                }
            }
        }
        return sum;
    }
};