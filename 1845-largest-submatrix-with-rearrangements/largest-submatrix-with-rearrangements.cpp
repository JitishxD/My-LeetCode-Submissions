class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(matrix[r][c] == 1 && r>0){
                    matrix[r][c] += matrix[r-1][c]; //cumulative 1s
                }
            }
            vector<int> heights = matrix[r];
            sort(heights.begin(), heights.end(), greater<int>());

            for(int i=0; i<n; i++){
                int base = i+1;
                int height = heights[i];
                maxArea = max(maxArea, base*height);
            }
        }
        return maxArea;
    }
};