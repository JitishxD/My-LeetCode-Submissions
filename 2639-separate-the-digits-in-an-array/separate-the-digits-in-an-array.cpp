class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        for (int num : nums) {
            int temp[10]; // A 32-bit int has at most 10 digits
            int count = 0;
            
            // Extract digits (they come out in reverse)
            while (num > 0) {
                temp[count++] = num % 10;
                num /= 10;
            }
            
            // Push them into the answer array in the correct order
            for (int i = count - 1; i >= 0; i--) {
                ans.push_back(temp[i]);
            }
        }
        
        return ans;
    }
};