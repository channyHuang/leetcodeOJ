class Solution {
public:
    int res;

    int maxLength(vector<string>& arr) {
        int len = arr.size();
        if (len <= 0) return 0;
        bool used[len];
        int nums[len];
        int arrlen[len];
        memset(used, 0, sizeof(used));
        memset(nums, 0, sizeof(nums));
        memset(arrlen, 0, sizeof(arrlen));
        for (int i = 0; i < len; i++) {
            arrlen[i] = arr[i].length();
            if (i > 0) arrlen[i] += arrlen[i - 1];
            for (int j = 0; j < arr[i].length(); j++) {
                int bit = arr[i][j] - 'a';
                if ((nums[i] & (1 << bit)) != 0) {
                    used[i] = true;
                    break;
                }
                nums[i] |= (1 << bit);
            }
        }
        res = 0;
        search(arr, nums, used, arrlen, 0, 0, 0);
        return res;
    }

    void search(vector<string>& arr, int nums[], bool used[], int arrlen[], int pos, int curNum, int curLen) {
        if (curLen > res) res = curLen;
        if (res >= arrlen[arr.size() - 1]) return;
        for (int i = pos; i < arr.size(); i++) {
            if (used[i]) continue;
            if ((curNum & nums[i]) != 0) continue;
            used[i] = true;
            search(arr, nums, used, arrlen, pos + 1, curNum | nums[i], curLen + arr[i].length());
            if (res >= arrlen[arr.size() - 1]) return;
            if (arrlen[pos] - curLen > arrlen[arr.size() - 1] - res) return;
            used[i] = false;
        }
    }
};
