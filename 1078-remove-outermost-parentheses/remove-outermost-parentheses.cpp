class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();

        int count = 0;
        int lastIndex = 1;
        string ans;
        for(int i=0; i<n-1; i++){
            if(s[i] == '(') {
                count++;
            } else if(s[i] == ')') {
                count--;
            }

            if(s[i] == ')' && s[i+1] == '(' && count==0) {
                ans+=s.substr(lastIndex, i-lastIndex);
                lastIndex = i+2;
            }
        }

        ans += s.substr(lastIndex, n-1-lastIndex);

        return ans;

    }
};