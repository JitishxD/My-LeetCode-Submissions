class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> dt;
        int n = nums.size();
        int ans = 0;
        int i=0, j=0;

        while(j<n){
            dt[nums[j]]++;
            while(i<j && dt[nums[j]] > k) {
                dt[nums[i]]--;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};