class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        int pos = n - 1;
        while (k) {
            if (k >= 25) {
                res[pos] = 'z';
                k -= 25;
            } else {
                res[pos] += k;
                break;
            }
            pos--;
        }
        return res;
    }
};
