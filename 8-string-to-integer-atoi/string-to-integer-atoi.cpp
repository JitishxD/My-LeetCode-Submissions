class Solution {
public:
    int findAtoi(string &s, int i, int res, int sign) {
        if (i >= s.length() || s[i] < '0' || s[i] > '9')
            return res * sign;

        if (res > INT_MAX/10 || (res == INT_MAX/10 && s[i] > '7'))
            return sign == 1 ? INT_MAX : INT_MIN;

        res = res * 10 + (s[i] - '0');
        return findAtoi(s, i + 1, res, sign);
    }

    int myAtoi(string s) {
        int i = 0, sign = 1;

        while (i < s.length() && s[i] == ' ')
            i++;

        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return findAtoi(s, i, 0, sign);
    }
};