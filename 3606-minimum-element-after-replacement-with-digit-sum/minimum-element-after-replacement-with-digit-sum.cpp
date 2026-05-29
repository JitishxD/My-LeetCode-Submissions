class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int temp=0;
            while(nums[i]!=0){
                int digit = nums[i]%10;
                temp += digit;
                nums[i] /= 10;
            }
            nums[i] = temp;
        }

        return *min_element(nums.begin(), nums.end());
    }
};