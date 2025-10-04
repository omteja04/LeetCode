class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, area = 0, currarea = 0;
        while (left <= right) {
            currarea = min(height[left], height[right]) * (right - left);
            area = max(area, currarea);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return area;
    }
};