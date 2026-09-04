class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> dt1, dt2, ans;
        int n = nums.size();
        bool flag = true;
        for(int n: nums){
            if(n>0) dt1.push_back(n);
            else dt2.push_back(n);
        }

        int d=0, j=0;
        while(n--) {
            if(flag) {
                ans.push_back(dt1[d]);
                d++;
            } else {
                ans.push_back(dt2[j]);
                j++;
            }

            flag = !flag;
        }

        return ans;
    }
};