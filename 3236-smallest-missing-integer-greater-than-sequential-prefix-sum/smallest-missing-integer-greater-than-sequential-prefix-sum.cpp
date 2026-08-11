class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> dt(begin(nums), end(nums));

        int ans = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]+1) {
                break;
            }

            ans+=nums[i];
        }

        while(dt.find(ans) != dt.end()) {
            ans++;
        }

        return ans;
    }
};