class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]) {
                int temp = nums[i];
                nums[i] = nums[dt];
                nums[dt] = temp;
                dt++;
            }
        }
    }
};