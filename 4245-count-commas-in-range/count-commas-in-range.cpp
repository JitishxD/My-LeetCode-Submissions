class Solution {
public:
    int countCommas(int n) {
        int dt = 0, j = n;
        while(j!=0) {
            int digit = j%10;
            j /= 10;
            dt++;
        }

        if(dt<4) return 0;

        return n-1000+1;
    }
};