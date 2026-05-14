class Solution {
public:
    bool isGood(vector<int>& nums) {
        int baseN = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> freq(baseN+1, 0);
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        for(int i=1; i<baseN; i++){
            if(freq[i]!=1) return false;
        }

        return freq[baseN] == 2;
    }
};