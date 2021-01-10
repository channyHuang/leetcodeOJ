class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int nw = n / 7;
        int rw = n % 7;
        
        int end = 0;
        if (nw > 0) {
            int st = 28;
            end = 28 + 7 * (nw - 1);
            res = (st + end) * nw / 2;
        }
        end = nw + 1;
        for (int i = 0; i < rw; i++) {
            res += end;
            end++;
        }
        //cout << nw << " " << rw << " " << res << endl;
        return res;
    }
};
