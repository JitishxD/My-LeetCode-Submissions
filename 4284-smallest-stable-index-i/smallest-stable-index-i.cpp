class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> dt1;
        vector<int> dt2;
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++){
            int currMax = INT_MIN;
            for(int j=0; j<=i; j++){
                currMax = max(currMax, nums[j]);
            }
            dt1.push_back(currMax);
        }

        for(int i=0; i<n; i++){
            int currMin = INT_MAX;
            for(int j=i; j<n; j++){
                currMin = min(currMin, nums[j]);
            }
            dt2.push_back(currMin);
        }

        for(int i=0; i<n; i++){
            int dtj = dt1[i] - dt2[i];
            if(dtj<=k) {
                return i;
            }
        }

        return -1;

    }
};