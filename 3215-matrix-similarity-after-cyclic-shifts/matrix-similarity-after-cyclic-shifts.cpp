class Solution {
public:
    void rShift(vector<int>& row, int k){
        reverse(row.begin(), row.end());
        reverse(row.begin(), row.begin()+k);
        reverse(row.begin()+k, row.end());
    }

    void lShift(vector<int>& row, int k){
        reverse(row.begin(), row.begin()+k);
        reverse(row.begin()+k, row.end());
        reverse(row.begin(), row.end());
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k % m;
        if(k==0) return true;

        vector<vector<int>> original = mat;

        for(int i=0; i<n; i++){
            if(i % 2 == 0) lShift(mat[i], k);
            else rShift(mat[i], k);
        }

        return mat == original;
    }
};