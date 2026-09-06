class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid;
        int l = 0, r = nums.size() - 1;
        // When l == r, only one element remains in the search space,
        // which must be the minimum element.
        while (l < r) {
            mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                // move right (Discarding mid, because it's greater than
                // nums[r], so it can't be the minimum element)
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};