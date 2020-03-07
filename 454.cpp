
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int target = A[i] + B[j];
                itr = maps.find(target);
                if (itr != maps.end()) itr->second++;
                else maps.insert(pair<int, int>(target, 1));
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int target = C[i] + D[j];
                itr = maps.find(-target);
                if (itr != maps.end()) {
                    res += itr->second;
                }
            }
        }
        return res;
    }
};
