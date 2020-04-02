class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string stStr = to_string(low);
        string endStr = to_string(high);
        vector<int> res;
        for (int len = stStr.length(); len <= endStr.length(); len++) {
            for (int i = 1; i <= 10 - len; i++) {
                int num = 0;
                int bit = len;
                for (int k = i; k < i + len; k++) {
                    num = num * 10 + k;
                    bit--;
                }
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
                if (num > high) break;
            }
        }
        return res;
    }
};
