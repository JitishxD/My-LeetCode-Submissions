class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int dt = 0;
        int j = 0;
        for(int i: nums) {
            if(i) dt++;
            else dt = 0;
            j = max(dt, j);
        }

        return j;
    }
};