class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> res(2, -1);
        len = A.size();
        vector<int> index;
        total = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] == 1) {
                index.push_back(i);
                total++;
            }
        }
        if (total % 3 != 0) return res;
        if (total == 0) {
            return vector<int>{0, 2};
        }
        total /= 3;
        len = index.size(); //len = total * 3
        int last0 = A.size() - index[len - 1] - 1;
        //cout << "total = " << total << " " << last0 << endl;

        if (index[total] - index[total - 1] - 1 < last0 || index[len - total] - index[len - total - 1] - 1 < last0) return res;
        res[0] = index[total - 1] + last0;
        res[1] = index[len - total - 1] + last0 + 1;
        //cout << "res = " << res[0] << " " << res[1] << endl;
        int pos2 = len - total - 2;
        int pos1 = total - 2;
        int pos3 = len - 2;
        while (pos1 >= 0) {
            if (index[pos3 + 1] - index[pos3] != index[pos2 + 1] - index[pos2]) return vector<int>{-1, -1};
            if (index[pos3 + 1] - index[pos3] != index[pos1 + 1] - index[pos1]) return vector<int>{-1, -1};
            pos3--;
            pos2--;
            pos1--;
        }
        
        return res;
    }

private:
    int len;
    int total;
};
