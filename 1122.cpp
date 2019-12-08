class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size(), len2 = arr2.size();
        int count[1001] = {0};
        vector<int> res;
        for (int i = 0; i < len1; i++) {
            count[arr1[i]]++;
        }
        for (int i = 0; i < len2; i++) {
            for (int j = 0; j < count[arr2[i]]; j++) res.push_back(arr2[i]);
            count[arr2[i]] = 0;
        }
        for (int i = 0; i < 1001; i++) {
            if (count[i] > 0) {
                for (int j = 0; j < count[i]; j++) res.push_back(i);
            }
        }
        return res;
    }
};
