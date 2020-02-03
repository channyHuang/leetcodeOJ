class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        if (len <= 0) return arr;
        vector<int> res;
        res.resize(len);
        res[len - 1] = -1;
        if (len <= 1) return res;
        int curIdx = len - 1;
        for (int i = len - 2; i >= 0; i--) {
            int tmpIdx = curIdx;
            if (arr[i] >= arr[curIdx]) {
                curIdx = i;
            }
            res[i] = arr[tmpIdx];
        }    
        return res;
    }
};