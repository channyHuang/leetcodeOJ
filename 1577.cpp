class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        len1 = 1;
        len2 = 1;
        int res = 0;
        count1.resize(nums1.size(), 1);
        count2.resize(nums2.size(), 1);
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] == nums1[len1 - 1]) count1[len1 - 1]++;
            else {
                nums1[len1++] = nums1[i];
            }
        }
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] == nums2[len2 - 1]) count2[len2 - 1]++;
            else {
                nums2[len2++] = nums2[i];
            }
        }
        for (int i = 0; i < len1; i++) {
            if (count1[i] > 1) {
                long long mul = (long long)nums1[i] * nums1[i];
                maps1[mul] += (count1[i] * (count1[i] - 1) >> 1);
            }
            for (int j = i + 1; j < len1; j++) {
                long long mul = (long long)nums1[i] * nums1[j];
                maps1[mul] += count1[i] * count1[j];
            }
        }
        for (int i = 0; i < len2; i++) {
            if (count2[i] > 1) {
                long long mul = (long long)nums2[i] * nums2[i];
                maps2[mul] += (count2[i] * (count2[i] - 1) >> 1);
            }
            for (int j = i + 1; j < len2; j++) {
                long long mul = (long long)nums2[i] * nums2[j];
                maps2[mul] += count2[i] * count2[j];
            }
        }
        for (int i = 0; i < len1; i++) {
            unordered_map<long long, int>::iterator itr = maps2.find((long long)nums1[i] * nums1[i]);
            if (itr != maps2.end()) {
                res += (count1[i] * itr->second);
            }
        }
        for (int i = 0; i < len2; i++) {
            unordered_map<long long, int>::iterator itr = maps1.find((long long)nums2[i] * nums2[i]);
            if (itr != maps1.end()) {
                res += (count2[i] * itr->second);
            }
        }
        return res;
    }
private:
    int len1, len2;
    vector<int> count1, count2;
    unordered_map<long long, int> maps1, maps2;
};
