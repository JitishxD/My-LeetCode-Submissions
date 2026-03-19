class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        string chars = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0; i<n; i++){
            if(s[i]!='?') continue;
            else {
                for(char c: chars){
                    if ((i == 0 || s[i-1] != c) && (i == n-1 || s[i+1] != c)){
                        s[i] = c;
                        break;
                    }
                }
            }
        }

        return s;
    }
};