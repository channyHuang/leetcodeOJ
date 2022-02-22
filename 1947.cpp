class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int len = students.size();
        int slen = students[0].size();
        vector<int> sts;
        vector<int> mes;
        for (int i = 0; i < len; ++i) {
            int singlest = 0;
            int singleme = 0;
            for (int j = 0; j < slen; ++j) {
                singlest <<= 1;
                singlest += students[i][j];
                singleme <<= 1;
                singleme += mentors[i][j];
            }
            sts.push_back(singlest);
            mes.push_back(singleme);
        }
        int res = 0;
        vector<int> index(len, 0);
        for (int i = 1; i < len; ++i) index[i] = i;

        do {
            int tmp = 0;
            for (int i = 0; i < len; ++i) {
                tmp += (slen - calcBit(sts[i] ^ mes[index[i]]));
            }
            res = std::max(res, tmp);
        } while (nextindex(index, len));

        return res;
    }

    bool nextindex(vector<int> &index, int len) {
        int pos = len - 1;
        while (pos > 0) {
            if (index[pos] > index[pos - 1]) {
                sort(index.begin() + pos, index.end());
                int idx = pos;
                while (idx < len) {
                    if (index[pos - 1] < index[idx]) {
                        break; 
                    }
                    idx++;
                }
                int tmp = index[pos - 1];
                index[pos - 1] = index[idx];
                index[idx] = tmp;
                return true;
            }
            pos--;
        }
        return false;
    }

    int calcBit(int n) {
        int sum = 0;
        while (n > 0) {
            n &= (n - 1);
            sum++;
        }
        return sum;
    }
};
