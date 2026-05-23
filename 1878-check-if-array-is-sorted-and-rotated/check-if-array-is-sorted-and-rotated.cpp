class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool firstCheck = true;
        int k = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                k = i;
                firstCheck = false;
                break;
            }
        };

        if (!firstCheck) {
            for (int i = k + 1; i < n - 1; i++) {
                if (nums[i] > nums[i + 1]) return false;
            }

            if (nums[n - 1] > nums[0]) return false;
        }

        return true;
    }
};