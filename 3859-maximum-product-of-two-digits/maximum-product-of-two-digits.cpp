class Solution {
public:
    int maxProduct(int n) {
        int m1 = 0, m2 = 0;
        while(n != 0){
            int digit = n % 10;
            n /= 10;
            if(m1<digit) {
                m2 = m1;
                m1 = digit;
            } else if (m2<digit){
                m2 = digit;
            }
        }

        return m1*m2;
    }
};