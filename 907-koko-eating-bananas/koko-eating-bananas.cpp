class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int j = *max_element(piles.begin(), piles.end());
        int start=1, end=j;
        int dt = INT_MIN;
        while(start<=end){
            int k = start + (end-start)/2;
            long long curr = 0;
            for(int kelas: piles) {
                curr += ((long long)kelas + k - 1) / k;
            }

            if(curr<=h) {
                end = k-1;
            } else {
                start = k+1;
            }
        }

        return start;
    }
};