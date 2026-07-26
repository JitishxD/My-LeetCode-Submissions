class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m3 = nums[n-1];
        int m1 = 0, m2 = 0;
        int n1 = 0, n2 =0;

        if(m3<0){
            return (long long) nums[n-1]*nums[n-2]*nums[n-3];
        }

        if(nums[0]<0 && nums[1]<0) {
            n1 = nums[0];
            n2 = nums[1];
        }

        if(nums[n-2]>0 && nums[n-3]>0) {
            m1 = nums[n-3];
            m2 = nums[n-2];
        }
        
        if ((long long) m1*m2 > (long long) n1*n2) {
            return m1*m2*m3;
        }

        return n1*n2*m3;
    }
};