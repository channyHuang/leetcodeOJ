class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> sets1, sets2;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) sets1.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i++) {
            if (sets1.find(nums2[i]) != sets1.end()) {
                sets2.insert(nums2[i]);
            }
        }
        for (set<int>::iterator itr = sets2.begin(); itr != sets2.end(); itr++) {
            res.push_back(*itr);
        }
        return res;
    }
};
