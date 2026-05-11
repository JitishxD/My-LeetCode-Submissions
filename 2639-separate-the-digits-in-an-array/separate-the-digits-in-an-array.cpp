class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            while(nums[i]!=0){
                int digit = nums[i]%10;
                ans.push_back(digit);
                nums[i] /= 10;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};