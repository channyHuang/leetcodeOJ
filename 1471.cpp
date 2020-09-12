class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int len = arr.size();
        if (k == len) return arr;
        sort(arr.begin(), arr.end());
        vector<int> res;
        int stPos = 0, endPos = len - 1;
        midn = arr[(len - 1) / 2];
        while (stPos < endPos) {
            if (stronger(arr[stPos], arr[endPos])) {
                res.push_back(arr[stPos]);
                stPos++;
            } else {
                res.push_back(arr[endPos]);
                endPos--;
            }
            if (res.size() >= k) break;
        }
        return res;
    }

    bool stronger(int a, int b) {
        if (abs(a - midn) > abs(b - midn)) return true;
        if (abs(a - midn) < abs(b - midn)) return false;
        return a > b;
    }
private:
    int midn;
};
