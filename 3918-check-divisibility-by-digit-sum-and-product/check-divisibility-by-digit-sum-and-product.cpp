class Solution {
public:
    bool checkDivisibility(int n) {
        int dt1 = 0;
        int dt2 = 1;
        int temp = n;
        while(temp != 0){
            int digit = temp % 10;
            dt1 += digit;
            dt2 *= digit;
            temp /= 10;
        }

        if((n % (dt1 + dt2)) == 0) return true;

        return false; 
    }
};
