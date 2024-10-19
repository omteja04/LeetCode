class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length < 1 || matrix[0].length <1) {
            return false;
        }
        int low = 0;
        int high = matrix[0].length - 1;
        while(low <= matrix.length - 1 && high  >= 0) {
            if(matrix[low][high] == target)  return true;
            else if(matrix[low][high] > target) {
                high--;
            } else {
                low++;
            }
        }
        return false;
    }
}