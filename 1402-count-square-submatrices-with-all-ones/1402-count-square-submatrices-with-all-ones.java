class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int ans = 0;
        for(int i = 0 ;i < m; i++) {
            for(int j = 0; j  < n; j++) {
                if(i > 0 && j > 0 && matrix[i][j] == 1) {
                    matrix[i][j] = Integer.max(matrix[i][j], 1 + Integer.min(matrix[i - 1][j], Integer.min(matrix[i][j - 1], matrix[i - 1][j - 1])));
                }
                ans += matrix[i][j];
            }
        }
        return ans;

    }
}