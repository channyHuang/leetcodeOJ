class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        vector<int> res;
        if (x <= arr[0]) {
            for (int i = 0; i < k; i++) res.push_back(arr[i]);
            return res;
        }
        if (x >= arr[len - 1]) {
            for (int i = len - k; i < len; i++) res.push_back(arr[i]);
            return res;
        }

        int smallOrEqual = 0, large = len - 1;
        while (smallOrEqual < large) {
            int midPos = (smallOrEqual + large) / 2;
            if (arr[midPos] > x) large = midPos;
            else if (arr[midPos] <= x) smallOrEqual = midPos;
            if (large - smallOrEqual <= 1) break;
        }

        while (k) {
            if (smallOrEqual >= 0 && large < len) {
                if (x - arr[smallOrEqual] <= arr[large] - x) {
                    res.push_back(arr[smallOrEqual--]);
                } else {
                    res.push_back(arr[large++]);
                }
            } else if (smallOrEqual >= 0) {
                res.push_back(arr[smallOrEqual--]);
            } else {
                res.push_back(arr[large++]);
            }
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
