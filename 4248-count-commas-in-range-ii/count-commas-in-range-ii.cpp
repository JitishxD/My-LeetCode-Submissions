class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long dt = 0;
        long long j = 1000;
        while(j<=n) {
            dt += (n-j+1);
            j *= 1000;
        }

        return dt;


    }
};