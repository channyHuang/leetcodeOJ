class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        if (num <= 0) return res;
        res.push_back(1);
        for (int i = 2; i <= num; i++) {
            int m = i;
            int tmp = 0;
            while (m) {
                tmp++;
                m = m&(m-1);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

/*
为什么这种方法比上一种还慢？

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        if (num <= 0) return res;
        res.push_back(1);
        for (int i = 2; i <= num; i++) {
            res.push_back(1 + res[i & (i-1)]);
        }
        return res;
    }
};
*/
