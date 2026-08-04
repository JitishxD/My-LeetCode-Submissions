class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n1 = *min_element(nums.begin(), nums.end());
        int n2 = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        unordered_set<int> present(nums.begin(), nums.end());

        for (int curr=n1; curr<=n2; curr++) {
            if (present.find(curr) == present.end()) {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};