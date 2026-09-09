class Solution {
public:
    int arrangeCoins(int n) {
        long long start =1, end = n;
        while(start<=end){
            long long dt = start+(end-start)/2;
            long long j = (dt*(dt+1))/2;

            if(j == n) return dt;
            else if(j<n) start = dt+1;
            else end = dt-1;
        }

        return end;
    }
};