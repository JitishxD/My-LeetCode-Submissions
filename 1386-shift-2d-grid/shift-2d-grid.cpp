class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = n*m;
        k = k%sz;
        if (!k) return grid;

        // The element present on 6th index in 1D array will be on 
        // row = 6/col = 6/3 = 2 
        // col = 6%col = 6%3 = 0
        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / m][i % m], grid[j / m][j % m]);
                i++;
                j--;
            }
        };
        
        reverse(0, sz - 1);
        reverse(0, k - 1);
        reverse(k, sz - 1);

        return grid;
    }
};