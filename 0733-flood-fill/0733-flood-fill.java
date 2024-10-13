class Solution {
    private void dfs(int sr, int sc,int initialColor, int newColor, int[][] res, int[] dx, int[] dy, int[][] image) {
        int m = image.length;
        int n = image[0].length;
        res[sr][sc] = newColor;
        for(int i = 0; i < 4; i++) {
            int x = sr + dx[i];
            int y = sc + dy[i];
            if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == initialColor && res[x][y] != newColor) {
                dfs(x, y, initialColor, newColor, res, dx, dy, image);
            }
        }

    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        int[][] res = image;
        int m = image.length;
        int n = image[0].length;
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};
        dfs(sr, sc, initialColor, color, res, dx, dy, image);
        return res;
    }
}