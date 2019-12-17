class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int len1 = nums1.size(), len2 = nums2.size();
        int pos = 0;
        for (int i = 0; i < len1; i++) {
            while (pos < len2 && nums2[pos] < nums1[i]) pos++;
            if (pos >= len2) return res;
            if (nums2[pos] == nums1[i]) {
                res.push_back(nums1[i]);
                pos++;
            }
        }
        return res;
    }
};
