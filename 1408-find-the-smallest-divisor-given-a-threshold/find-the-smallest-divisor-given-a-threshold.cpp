class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int dt = *max_element(nums.begin(), nums.end());
        int start=1, end=dt;
        while(start<=end){
            int k = start + (end-start)/2;
            long long curr = 0;
            for(int n: nums) {
                curr += ((long long)n + k - 1) / k;
            }

            if(curr<=threshold) {
                end = k-1;
            } else {
                start = k+1;
            }
        }

        return start;
    }
};