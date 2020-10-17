class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        //arr[i]的大小在[0, 10**8]之间。
        int minn = INT_MAX;
        int mincount = 0;
        int res = 0;
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());
        vector<int> count(len, 0);
        for (int i = len - 1; i >= 0; i--) {
            if (i < len - 1 && sorted[i] == sorted[i + 1]) count[i] = count[i + 1] + 1;
            else count[i] = 1;

            if (minn > arr[i]) {
                minn = arr[i];
                mincount = 1;
            } else if (minn == arr[i]) {
                mincount++;
            }

            if (minn == sorted[i] && count[i] == mincount) {
                res++;
                minn = INT_MAX;
                count[i] = 0;
            }
        }
        return res;
    }
};
