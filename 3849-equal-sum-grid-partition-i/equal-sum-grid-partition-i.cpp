class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int h = 0;
        int v = 0;

        vector<long long> hSum(n);
        vector<long long> vSum(m);

        long long first = 0, second = 0, total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hSum[i] += grid[i][j];   // row sum
                vSum[j] += grid[i][j];   // column sum
                total += grid[i][j];     // total sum
            }
        }

        // Horizontal cuts
        while (h < n - 1) {
            first += hSum[h];
            second = total - first;
            if (first == second) return true;
            h++;
        }
        
        // Vertical cuts
        first = 0;
        second = 0;
        while(v < m - 1) {
            first += vSum[v];
            second = total - first;

            if (first == second) return true;
            v++;
        }

        return false;
    }
};