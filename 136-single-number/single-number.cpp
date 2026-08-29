class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int dt = 0;
        for(int i: nums){
            dt ^= i;
        }

        return dt;
    }
};