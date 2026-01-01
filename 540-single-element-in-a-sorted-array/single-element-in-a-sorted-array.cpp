class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        // exclude first and last index
        int low = 1, high = n - 2;
        
        while (low <= high) {
            int mid = low+(high-low)/2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // If mid is in the left half (pairing is valid)
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            }
            // If mid is in the right half (pairing broken earlier)
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};