// Diffrence Array Technique (DAT)
// Ref: https://www.youtube.com/watch?v=ZHNVmtm08WY&list=PLpIkg8OmuX-Kqkb8DqDe_4-Tiav6ilS_L&index=2
// Sol: https://www.youtube.com/watch?v=OzBKFDXNCkY
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2*limit+2, 0); // or Target Sum array

        for (int i=0; i<n/2; i++) {

            int a = nums[i];
            int b = nums[n-1-i];

            int minVal = min(a, b) + 1;
            int maxVal = max(a, b) + limit;

            // (2, 2*limit, +2) 
            diff[2] += 2;
            diff[2*limit+1] -= 2;

            // for moves = 1
            // (minVal, maxVal, -1)
            diff[minVal] += (-1);
            diff[maxVal+1] -= (-1);

            // for moves = 0 
            // (a+b, a+b, -1)
            diff[a+b] += (-1);
            diff[a+b+1] -= (-1);
        }

        int result = INT_MAX;

        // Convert diff into its cumulative form and track the minimum cost
        // index 0,1 = 0 so they have no effect so start from 2
        for (int targetSum = 2; targetSum <= 2*limit; targetSum++) {
            diff[targetSum] += diff[targetSum-1];

            result = min(result, diff[targetSum]);
        }

        return result;
    }
};