class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        // bound -> m-k and n-k
        for (int r = 0; r <= m - k; r++) {
            for (int c = 0; c <= n - k; c++) {
                // auto sort or use vector+sort
                set<int> submat;
                for (int i = r; i < r + k; i++) {
                    for (int j = c; j < c + k; j++) {
                        submat.insert(grid[i][j]);

                        // If all elements were same, set has only 1 element
                        if (submat.size() == 1) continue;

                        int minAbsDiff = INT_MAX;
                        auto prev = submat.begin();
                        auto curr = next(prev);

                        while (curr != submat.end()) {
                            minAbsDiff = min(minAbsDiff, *curr - *prev);
                            prev = curr;
                            curr++;
                        }

                        ans[r][c] = minAbsDiff;
                    }
                }
            }
        }
        return ans;
    }
};