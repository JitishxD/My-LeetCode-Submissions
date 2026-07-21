class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i = 0, j = 0, k = 0;
        int n = s.size();
        int ans = 0, ones = 0;

        while (k < n && s[k] == '0') {
            i++;
            k++;
        }

        while (k < n) {
            if (s[k] == '1') {
                ones++;
                k++;
            } else {
                j = 0;
                while (k < n && s[k] == '0') {
                    j++;
                    k++;
                }
                
                if (i > 0 && j > 0) {
                    ans = max(ans, i + j);
                }
                
                i = j;
            }
        }

        return ones + ans;
    }
};