class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int len = A.size();
        if (len == 1) return A;
        vector<int> res;
        res.resize(len);
        sort(A.begin(), A.end(), greater<int>());
        map<int, vector<int>> maps;
        map<int, vector<int>>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(B[i]);
            if (itr == maps.end()) {
                vector<int> sub;
                sub.push_back(i);
                maps.insert(pair<int, vector<int>>(B[i], sub));
            } else {
                itr->second.push_back(i);
            }
        }
        itr = maps.end();
        itr--;
        int pos = 0;
        int endPos = len - 1;
        while (1) {
            for (int i = 0; i < itr->second.size(); i++) {
                if (A[pos] > itr->first) {
                    res[itr->second[i]] = A[pos++];
                } else {
                    res[itr->second[i]] = A[endPos--];
                }
            }
            if (itr == maps.begin()) break;
            itr--;
        }
        return res;
    }
};
