class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        int n = nums.size();

        // store indices
        for(int i=0; i<n; i++){
            um[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto &it : um){
            vector<int> curr = it.second;

            if(curr.size() < 3) continue;

            for(int i=0; i<curr.size(); i++){
                // because curr[i+2] can go out of range
                if(i+2<curr.size()) {
                    ans = min(ans, 2*(curr[i+2]-curr[i]));
                }
            }
        }

        return (ans==INT_MAX ? -1 : ans);
    }
};