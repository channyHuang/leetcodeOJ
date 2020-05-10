class Solution {
public:
    string getHappyString(int n, int k) {
        int maxn = 3 * pow(2, n - 1);
        if (k > maxn) return "";
        if (n == 1) return (k == 1 ? "a" : (k == 2 ? "b" : "c"));
        string res;
        if (k <= maxn / 3) {
            res += "a";
        }
        else if (k <= maxn / 3 * 2) {
            res += "b";
            k -= maxn / 3;
        } else {
            res += "c";
            k -= maxn / 3 * 2;
        }
        n--;
        int pos = 0;
        while (n) {
            int half = pow(2, n - 1);
            if (k <= half) {
                res += (res[pos] == 'a' ? "b" : "a");
            } else {
                res += (res[pos] == 'c' ? "b" : "c");
                k -= half;
            }
            pos++;
            n--;
        }
        return res;
    }
};
