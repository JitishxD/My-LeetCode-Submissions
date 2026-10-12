class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                //i is a factor of n, so nums[i-1]*nums[i-1]
                result += nums[i - 1] * nums[i - 1];

                if (i * i != n) { //if not prefect sqaure
                    //n/i is the other factor, so nums[n/i-1]*nums[n/i-1]
                    result += nums[n / i - 1] * nums[n / i - 1];
                }

            }
        }
        return result;
    }
};