class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int len = A.size();
        set<int> res;
        int maxn = 0;
        for (int i = 0; i < len; i++) {
            if (i > 0 && A[i] == A[i - 1]) continue;
            int tmp = A[i];
            res.insert(tmp);
            for (int j = i - 1; j >= 0; j--) {
                tmp |= A[j];
                res.insert(tmp);
                if (tmp & maxn == tmp) break;
            }
            maxn |= A[i];
        }
        return res.size();
    }
};


/*TLE
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int len = A.size();
        int result[len];
        memset(result, 0, sizeof(result));
        set<int> res;
        for (int i = 0; i < len; i++) {
            result[i] = A[i];
            res.insert(result[i]);
            for (int j = i + 1; j < len; j++) {
                result[j] = (result[j - 1] | A[j]);
                res.insert(result[j]);
            }
        }
        return res.size();
    }
};
*/
