class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int len = digits.size();
        
        bool flag = true;
        for (int i = 0; i < len; i++) {
            if (digits[i] != 9) {
                flag = false;
                break;
            }
        }
        int tarLen = len;
        if (flag) tarLen = len + 1;
        res.resize(tarLen);

        int add = 1;
        for (int i = len - 1; i >= 0; i--) {
            res[--tarLen] = digits[i] + add;
            add = 0;
            if (res[tarLen] >= 10) {
                res[tarLen] %= 10;
                add = 1;
            }
        }
        if (add) res[0] = 1;
        return res;
    }
};
