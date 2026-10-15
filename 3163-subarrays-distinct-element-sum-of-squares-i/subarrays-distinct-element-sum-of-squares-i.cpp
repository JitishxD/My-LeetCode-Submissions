class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            unordered_map<int, int> dt;
            int count = 0;

            for (int j=i; j<n; j++) {
                if (dt.find(nums[j]) == dt.end()) {
                    dt[nums[j]]++;
                    count++;
                }

                ans += count*count;
            }
        }

        return ans;
    }
};