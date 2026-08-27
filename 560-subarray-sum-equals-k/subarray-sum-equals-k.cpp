class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dt;
        dt[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            if (dt.find(remove) != dt.end()) {
                ans += dt[remove];
            }

            dt[prefixSum]++;
        }
        return ans;
    }
};