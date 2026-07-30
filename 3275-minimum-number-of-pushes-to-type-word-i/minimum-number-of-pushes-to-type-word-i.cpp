class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int multiplier = 1;
        int ans = 0;
        while(n>0){
            if(n<=8) {
                ans+=multiplier*n;
                break;
            }
            n = n - 8;
            ans+=multiplier*8;
            multiplier++;
        }
        return ans;
    }
};