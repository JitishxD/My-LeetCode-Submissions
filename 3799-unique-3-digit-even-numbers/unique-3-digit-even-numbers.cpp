class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> dt(10, 0);
        int ans =0;

        for(int j: digits) {
            dt[j]++;
        }

        // the hundred digit can go 1..9
        // avoiding leading zero
        for(int i=1; i<=9; i++) {
            if(dt[i] == 0) continue;
            dt[i]--;

            // the tens digit can go 0..9
            for(int j=0; j<=9; j++) {
                if(dt[j] == 0) continue;
                dt[j]--;

                // as the last digit would be even
                for(int k=0; k<=8; k+=2) {
                    if(dt[k] == 0) continue;
                    dt[k]--;
                    int num = i*100+j*10+k;
                    ans++; 
                    // we change the frequency back
                    // because we can reuse it any number of times
                    dt[k]++;
                }
                dt[j]++;
            }
            dt[i]++;
        }

        return ans;
    }
};