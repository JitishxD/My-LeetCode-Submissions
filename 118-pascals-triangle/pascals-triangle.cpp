class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr = {{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; j++) {
                temp[j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
            arr.push_back(temp);
        }
        
        return arr;
    }
};