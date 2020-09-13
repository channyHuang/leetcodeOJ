class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int len = arr.size();
        int stPos = 0;
        while (stPos < len - 1 && arr[stPos] <= arr[stPos + 1]) stPos++;
        if (stPos >= len - 1) return 0;
        int endPos = len - 1;
        while (endPos > 0 && arr[endPos] >= arr[endPos - 1]) endPos--;
        int res = min(len - stPos - 1, endPos);
        if (arr[len - 1] < arr[0]) return res;
        int left = 0;
        while (left <= stPos && arr[left] <= arr[endPos]) left++;
        res = min(res, endPos - left);
        //delete arr[left, endPos]
        left++;
        for (; endPos < len - 1; endPos++) {
            while (left <= stPos && arr[left] <= arr[endPos + 1]) left++;
            res = min(res, endPos - left + 1);
        }
        return res;
    }
};
