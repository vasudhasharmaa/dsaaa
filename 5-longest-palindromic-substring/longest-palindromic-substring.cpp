class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n == 1)
            return s;

        int maxLen = 1;
        int start = 0;

        for (int mid = 0; mid < n; mid++) {

            // Odd-length palindrome
            int i = mid - 1;
            int j = mid + 1;

            while (i >= 0 && j < n && s[i] == s[j]) {
                i--;
                j++;
            }

            i++;
            j--;

            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                start = i;
            }

            // Even-length palindrome
            i = mid;
            j = mid + 1;

            while (i >= 0 && j < n && s[i] == s[j]) {
                i--;
                j++;
            }

            i++;
            j--;

            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                start = i;
            }
        }

        return s.substr(start, maxLen);
    }
};