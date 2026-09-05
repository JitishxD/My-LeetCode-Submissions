class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxFromIndex;
        maxFromIndex.push_back(nums[0]);
        for(int i=1; i<n; i++){
            int currMax = max(maxFromIndex[i-1], nums[i]);
            maxFromIndex.push_back(currMax);
        }

        vector<int> minFromIndex(n);
        minFromIndex[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            minFromIndex[i] = min(minFromIndex[i+1], nums[i]);
        }

        for(int i=0; i<n; i++) {
            int maxElem = maxFromIndex[i];
            int minElem = minFromIndex[i];
            if((maxElem - minElem) <= k) {
                return i;
            }
        }

        return -1;
    }
};