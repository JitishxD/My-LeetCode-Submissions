class Solution {
public:
    int rj(int n) {
        int ans = 0;
        while(n!=0){
            int digit = n % 10;
            ans = ans*10+digit;
            n /= 10;
        }

        return ans;
    }

    int mirrorDistance(int n) {
        return abs(n-rj(n));
    }
};