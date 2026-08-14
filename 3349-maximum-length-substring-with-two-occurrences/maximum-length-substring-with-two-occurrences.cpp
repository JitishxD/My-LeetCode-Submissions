class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0, j=0;
        int n = s.length();
        unordered_map<char, int> dt;
        int ans = 0;

        while(j<n){ 
            dt[s[j]]++;
            while(dt[s[j]]>2) {
                dt[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};