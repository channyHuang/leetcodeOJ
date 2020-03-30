class Solution {
public:
    int findLucky(vector<int>& arr) {
        int len = arr.size();
        if (len <= 0) return -1;
        if (len == 1) return (arr[0] == 1 ? 1 : -1);
        sort(arr.begin(), arr.end(), greater<int>());
        int pos = 0;
        while (pos < len) {
            if (arr[pos] <= 0) return -1;
            if (pos > 0 && arr[pos] == arr[pos - 1]) {
                pos++;
                continue;
            }
            if (pos + arr[pos] > len) {
                pos++;
                continue;
            }
            if (pos + arr[pos] == len) {
                if (arr[len - 1] == arr[pos]) return arr[pos];
                else {
                    pos++;
                    continue;
                }
            }
            if (arr[pos + arr[pos] - 1] == arr[pos] && arr[pos + arr[pos]] != arr[pos]) return arr[pos];
            pos++;
        }
        return -1;
    }
};
