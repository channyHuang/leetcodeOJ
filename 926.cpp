class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int lens = S.length();
        vector<int> vec;
        int pos = 1;
        int tmp = 1;
        while (pos <= lens) {
            if (pos == lens) {
                vec.push_back(tmp);
                break;
            }
            if (S[pos] != S[pos - 1]) {
                vec.push_back(tmp);
                tmp = 1;
            } else {
                tmp++;
            }
            pos++;
        }
        lens = vec.size();
        if (lens <= 2) return 0;
        vector<int> to0(lens, 0);
        vector<int> to1(lens, 0);
        if (S[0] == '1') to0[0] = vec[0];
        if (S[S.length() - 1] == '0') to1[lens - 1] = vec[lens - 1];
        for (int i = 1; i < lens; i++) {
            if (S[0] == '0') {
                if (i & 1) to0[i] = to0[i - 1] + vec[i];
                else to0[i] = to0[i - 1];
            } else {
                if (i & 1) to0[i] = to0[i - 1];
                else to0[i] = to0[i - 1] + vec[i];
            }
        }
        int res = to0[lens - 1];
        for (int i = lens - 2; i >= 0; i--) {
            if (S[S.length() - 1] == '1') {
                if ((lens - i) & 1) to1[i] = to1[i + 1];
                else to1[i] = vec[i] + to1[i + 1];
            } else {
                if ((lens - i) & 1) to1[i] = vec[i] + to1[i + 1];
                else to1[i] = to1[i + 1];
            }
            res = min(res, to1[i + 1] + to0[i]);
        }
        res = min(res, to1[0]);
        return res;
    }
};
