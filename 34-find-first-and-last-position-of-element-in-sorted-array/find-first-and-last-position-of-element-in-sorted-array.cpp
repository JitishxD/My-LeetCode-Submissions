class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int j = upper_bound(nums.begin(), nums.end(), target)-nums.begin()-1;
        int dt = lower_bound(nums.begin(), nums.end(), target)-nums.begin();

        //prevent out of bound and check if the target is available or not?
        if (dt == nums.size() || nums[dt] != target) {
            return {-1, -1};
        }

        return {dt, j};
    }
};