class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        vector<int> prefix(n*m);
        vector<int> suffix(n*m);

        vector<vector<int>> ans(n, vector<int>(m));

        int idx = 0;
        long long prefixTemp = 1;
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                prefix[idx] = prefixTemp;
                prefixTemp = (prefixTemp * grid[r][c]) % MOD;
                idx++;
            }
        }

        idx=(n*m)-1;
        long long suffixTemp = 1;
        for(int r=n-1; r>=0; r--){
            for(int c=m-1; c>=0; c--){
                suffix[idx] = suffixTemp;
                suffixTemp = (suffixTemp * grid[r][c]) % MOD;
                idx--;
            }
        }

        // finally update the ans matrix!
        idx=0;
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                ans[r][c] = (prefix[idx]*suffix[idx]) % MOD;
                idx++;
            }
        }


        return ans;
    }
};