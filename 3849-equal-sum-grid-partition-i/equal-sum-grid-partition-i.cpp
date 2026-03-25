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
            long long temp = 0;
            for (int j = 0; j < m; j++) {
                temp += grid[i][j];
            }
            hSum[i] = temp;
            total += temp;
        }

        for (int j = 0; j < m; j++) {
            long long temp = 0;
            for (int i = 0; i < n; i++) {
                temp += grid[i][j];
            }
            vSum[j] = temp;
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