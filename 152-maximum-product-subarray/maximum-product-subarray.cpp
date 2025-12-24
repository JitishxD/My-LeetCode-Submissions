#include <climits>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftToRight = 1, rightToLeft = 1; 
        int maxProd = INT_MIN;

        for(int i=0; i<n; i++){
            if (leftToRight==0) leftToRight = 1;
            if (rightToLeft==0) rightToLeft = 1; 

            leftToRight *= nums[i];
            rightToLeft *= nums[n-1-i];

            maxProd = max({leftToRight, rightToLeft, maxProd});
        }

        return maxProd;
    }
};