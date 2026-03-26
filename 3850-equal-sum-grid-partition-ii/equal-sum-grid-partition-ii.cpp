class Solution {
public:
    long long total = 0;
    bool hCheck(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long top=0, bottom=0, diff=0;
        unordered_set<long long> d;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                d.insert(grid[i][j]);
                top += grid[i][j];
            }

            bottom = total-top;
            diff = top-bottom;

            if(diff == 0) return true;

            // When the top cut only have 1 row then we need these testcase
            if(diff == grid[0][0]) return true;
            if(diff == grid[0][m-1]) return true;

            // Suppose matrix of 1 column and n rows...
            if(diff == grid[i][0]) return true;
            if(i>0 && m > 1 && d.count(diff)) return true;
        }

        return false;

    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                total += grid[i][j];
            }
        }

        if(hCheck(grid)) return true;
        // Because we only check if diff=top-bottom which can be negative
        // hence we reverse the gird such that we get positive diff
        // then continue with our checks
        reverse(grid.begin(), grid.end());
        if(hCheck(grid)) return true;


        // Now we will check for Vertical Cuts by using
        // same function but with transpose hehehehehe BIG BRAIN!!!!
        vector<vector<int>> transposeGrid(m, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if(hCheck(transposeGrid)) return true;
        reverse(transposeGrid.begin(), transposeGrid.end());
        if(hCheck(transposeGrid)) return true;

        return false;

    }
};