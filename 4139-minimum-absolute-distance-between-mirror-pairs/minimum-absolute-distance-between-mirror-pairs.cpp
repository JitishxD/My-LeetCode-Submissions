class Solution {
public:
    int rj(int num){
        int ans = 0;
        while(num != 0){
            int digit = num % 10;
            ans = ans*10+digit;
            num /= 10;
        }

        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> um;
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if(um.find(nums[i]) != um.end()){
                ans = min(ans, i-um[nums[i]]);
            }

            um[rj(nums[i])] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};