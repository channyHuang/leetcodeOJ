class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res;
        for (int i = 1; i <= N; i++) {
            res.push_back(i);
        }
        resort(res, 0, N - 1);
        return res;
    }

    void resort(vector<int>& res, int stPos, int endPos) {
        if (endPos - stPos <= 1) return;
        vector<int> sub = res;
        int pos = stPos;
        for (int i = stPos; i <= endPos; i += 2) {
            res[pos++] = sub[i];
        }
        int midPos = pos;
        for (int i = stPos + 1; i <= endPos; i += 2) {
            res[pos++] = sub[i];
        }
        resort(res, stPos, midPos - 1);
        resort(res, midPos, endPos);
    }
};
