class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> res;
        
        int len = cont.size();
        if (len <= 0) return res;
        if (len <= 1) {
            res.push_back(cont[0]);
            res.push_back(1);
            return res;
        }
        int n = 0, m = 0;
        fractionOnce(cont, 0, n, m);
        res.push_back(n);
        res.push_back(m);
        return res;
    }
    //n/m
    void fractionOnce(vector<int> & cont, int stPos, int &n, int &m) {
        if (stPos == cont.size() - 1) {
            n = cont[cont.size() - 1];
            m = 1;
            return;
        } else {
            int x = 0, y = 0;
            fractionOnce(cont, stPos + 1, x, y);

            if (cont[stPos] == 0) {
                n = y;
                m = x;
            } else {
                m = x;
                n = cont[stPos] * x + y;
                int maxF = maxFactor(m, n);
                m /= maxF;
                n /= maxF;
            }
        }
    }

    int maxFactor(int a, int b) {
        int tmp;
        if (a < b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        while (b) {
            a = a % b;
            tmp = a;
            a = b;
            b = tmp;
        }
        return a;
    }
};
