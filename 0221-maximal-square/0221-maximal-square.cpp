class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int columns = matrix[0].size();

        vector<int> heights(columns, 0);
        // cout << heights.size();
        int maxArea = 0;

        for (auto& row : matrix) {
            for (int i = 0; i < columns; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            for (int i = 0; i < columns; i++) {
                int left = i;
                for (int x = i; x > 0 && heights[x - 1] >= heights[i]; x--) {
                    left--;
                }
                int right = i;
                for (int y = i; y < columns - 1 && heights[y + 1] >= heights[i];
                     y++) {
                    right++;
                }

                int side = min(heights[i], right - left + 1);
                maxArea = max(maxArea, side * side);
            }
        }
        return maxArea;
    }
};