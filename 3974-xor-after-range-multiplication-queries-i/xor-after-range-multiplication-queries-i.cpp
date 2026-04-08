class Solution {
public:
    int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int idx = 0;
        for(int i=0; i<queries.size(); i++){
            idx = queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx] = ( (long long) nums[idx]*queries[i][3]) % MOD;
                idx += queries[i][2];
            }
        }

        int ans = 0;
        for(int i: nums){
            ans ^= i;
        }

        return ans;
    }
};