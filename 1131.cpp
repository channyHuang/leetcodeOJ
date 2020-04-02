/*TLE
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int len = arr1.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int sum = abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j);
                if (res < sum) res = sum;
            }
        }
        return res;
    }
};
*/
