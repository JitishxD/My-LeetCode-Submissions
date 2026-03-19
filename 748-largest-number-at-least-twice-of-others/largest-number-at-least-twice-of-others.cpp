class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int currLargest = nums[0];
        int idx = 0;
        for(int i=1; i<nums.size(); i++){
            if(currLargest < nums[i]){
                currLargest = nums[i];
                idx = i;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(i == idx) continue;
            if(currLargest >= nums[i]*2) continue;
            else return -1;
        }
        return idx;
    }
};