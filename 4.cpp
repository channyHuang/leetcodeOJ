class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int targetPos = (len1 + len2) / 2;
        if ((len1 + len2) % 2 == 0) targetPos--;
        double res = 0;
        int p1 = 0, p2 = 0;
        while (targetPos--) {
            if (p1 < len1 && p2 < len2) {
                if (nums1[p1] <= nums2[p2]) p1++;
                else p2++;
            } else if (p1 < len1) {
                p1++;
            } else {
                p2++;
            }
        }

        if (p1 < len1 && p2 < len2) {
            if (nums1[p1] <= nums2[p2]) {
                res = nums1[p1];
                p1++;
            } else {
                res = nums2[p2];
                p2++;
            }
        } else if (p1 < len1) {
            res = nums1[p1];
            p1++;
        } else {
            res = nums2[p2];
            p2++;
        }

        if ((len1 + len2) % 2) return res;
        if (p1 < len1 && p2 < len2) {
            res += (nums1[p1] <= nums2[p2] ? nums1[p1] : nums2[p2]);
        } else if (p1 < len1) {
            res += nums1[p1];
        } else {
            res += nums2[p2];
        }
        return res / 2.0;
    }
};
