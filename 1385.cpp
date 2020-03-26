class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //0 <= d <= 100
        if (arr2.size() <= 0) return 0;
        sort(arr2.begin(), arr2.end());
        int res = 0;
        //-d <= arr2 - arr1 <= d ->> -d + arr1 <= arr2 <= d + arr1
        for (int i = 0; i < arr1.size(); i++) {
            if (!find(arr2, arr1[i], d)) res++;
        }
        return res;
    }

    bool find(vector<int>& arr2, int target, int d) {
        int stPos = 0, endPos = arr2.size() - 1;
        int minn = -d + target;
        int maxn = d + target;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (arr2[midPos] < minn) stPos = midPos + 1;
            else if (arr2[midPos] > maxn) endPos = midPos - 1;
            else return true;
        }
        return false;
    }
};
