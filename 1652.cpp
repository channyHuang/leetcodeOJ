class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len = code.size();
        vector<int> res(len, 0);
        if (k == 0) {
            return res;
        }
        if (k > 0) {
            for (int i = 0; i < len; i++) {
                int sum = 0;
                for (int j = i + 1; j <= i + k; j++) {
                    sum += code[j % len];
                }
                res[i] = sum;
            }
        } else {
            k = -k;
            for (int i = 0; i < len; i++) {
                int sum = 0;
                for (int j = i - 1; j >= i - k; j--) {
                    sum += code[(j + len) % len];
                }
                res[i] = sum;
            }
        }
        return res;
    }
};
