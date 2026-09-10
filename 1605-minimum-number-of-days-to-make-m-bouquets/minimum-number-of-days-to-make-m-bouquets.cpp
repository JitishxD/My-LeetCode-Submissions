class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if((long long) m*k>n) return -1;

        int start=0, end=*max_element(nums.begin(), nums.end());
        while(start < end) {
            int mid = start + (end- start)/2;
            int bouquets = 0;
            int curr_adj_flower = 0;
            for(int i=0; i<n; i++) {
                // because the flower bloom on day x is still bloomed at day mid where x<mid;
                if(nums[i]<=mid) {
                    curr_adj_flower++;
                    if (curr_adj_flower == k) {
                        bouquets++;
                        curr_adj_flower = 0;
                    }


                } else {
                    // Not adjacent we again initilise it to 0
                    curr_adj_flower = 0;
                }
            }
            

            if (bouquets >= m) end = mid;
            else start = mid + 1;
        }

        return start;
    }
};