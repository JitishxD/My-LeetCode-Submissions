class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> um;
        vector<int> ans;

        for (int num : nums) {
            um[num]++;
        }

        for (auto& pair : um) {
            if (pair.second > n / 3) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};