class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int c1 = m - 1;
        if (m == 0) {
            for (int i = 0; i < n; i++) nums1[i] = nums2[i];
            return;
        }
        int i = 0;
        for (i = n - 1; i >= 0; i--) {
            if (c1 < 0) break;
            if (nums2[i] >= nums1[c1]) {
                nums1[--len] = nums2[i];
            } else {
                nums1[--len] = nums1[c1];
                c1--;
                i++;
            }
        }

        for (; i >= 0; i--) {
            nums1[--len] = nums2[i];
        }
    }
};
