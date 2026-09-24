class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int curr = nums[i];
            int dt = 0;
            while(curr!=0) {
                int digit = curr % 10;
                dt += digit;
                curr /= 10;
            }

            if(dt==i) return dt;
        }

        return -1;
    }
};