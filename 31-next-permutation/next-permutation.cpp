class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int dt = -1;
        
        for(int i = n - 1; i > 0; i--) {
            if(nums[i-1] < nums[i]) {
                dt = i;
                break;
            }
        }
        
        if (dt == -1) {
            reverse(nums.begin(), nums.end());
            return; 
        }

        int j = n - 1;
        while (nums[j] <= nums[dt-1]) {
            j--;
        }

        swap(nums[dt-1], nums[j]);
        
        reverse(nums.begin()+dt, nums.end());
    }
};