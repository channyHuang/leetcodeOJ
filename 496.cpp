class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int index[100001] = {0};
        vector<int> res;
        int len1 = nums1.size(), len2 = nums2.size();
        for (int i = 0; i < len2; i++) {
            index[nums2[i]] = i + 1;
        }
        for (int i = 0; i < len1; i++) {
            int stPos = index[nums1[i]];
            while (stPos < len2 && nums2[stPos] <= nums1[i]) stPos++;
            if (stPos >= len2) res.push_back(-1);
            else res.push_back(nums2[stPos]);
        }
        return res;
    }
};
