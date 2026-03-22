class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // 90 -> transpose + reverse row
        int n = mat.size();
        int m = mat[0].size();
        int dt = 3;
        for(int i = 0; i < 4; i++) {
            if(isEqual(mat, target)) return true;
            rotate(mat);
        }

        return false;
    }

    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        for(int r=0; r<n; r++){
            for(int c=r+1; c<m; c++){
                swap(mat[r][c], mat[c][r]);
            }

            reverse(mat[r].begin(), mat[r].end());
        }
    }

    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(mat[r][c] != target[r][c]) return false;
            }
        }
        return true;
    }
};