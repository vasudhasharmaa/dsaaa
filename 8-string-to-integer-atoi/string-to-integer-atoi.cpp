class Solution {
public:
    int myAtoi(string s) {
        int temp = 0;
        int sign = +1;
        bool started = false;
        bool signseen = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && !started) {
                if (signseen)
                    return 0;

                continue;
            }
            if (s[i] == ' ' && started) {
                return temp * sign;
            }
            if (isalpha(s[i]))
                return temp * sign;
            if (!started && !(s[i] >= '0' && s[i] <= '9') && s[i] != '+' &&
                s[i] != '-' && s[i] != ' ')
                return 0;
            if (started && !(s[i] >= '0' && s[i] <= '9'))
                return temp * sign;
            if (s[i] == '-') {

                if (started == true) {
                    return temp * sign;
                } else {
                    if (signseen == true)
                        return temp * sign;
                    signseen = true;
                    sign = -1;
                    continue;
                }
            }

            if (s[i] == '+') {
                if (started == true) {
                    return temp * sign;
                } else {
                    if (signseen == true)
                        return temp * sign;
                    signseen = true;
                    sign = 1;
                    continue;
                }
            }

            if (s[i] >= '0' && s[i] <= '9') {
                if (temp > INT_MAX / 10 ||
                    (temp == INT_MAX / 10 && (s[i] - '0') > 7)) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }

                started = true;
                temp = temp * 10 + (s[i] - '0');
            }
        }
        return temp * sign;
    }
};