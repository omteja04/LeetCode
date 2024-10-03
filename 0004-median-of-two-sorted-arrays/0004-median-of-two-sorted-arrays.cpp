class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, m1 = 0,m2 = 0;

        for(int cnt = 0; cnt <= (m + n) / 2; cnt++) {
            m2 = m1;
            if(i != n && j != m) {
                if(nums1[i] > nums2[j]) {
                    m1 = nums2[j++];
                } else {
                    m1 = nums1[i++];
                }
            } else if(i < n) {
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
        }
        if ((m + n) % 2 == 1) {
            return static_cast<double>(m1);
        } 
        else {
            return (static_cast<double>(m1) + static_cast<double>(m2)) / 2.0;
        }
    }
};