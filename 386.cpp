class Solution {
public:
    vector<int> res;

    vector<int> lexicalOrder(int n) {
        res.clear();
        int x = 0;
        for (int i = 1; i < 10; i++) {
            x = i;
            if (i > n) break;
            res.push_back(i);
            search(n, i);
        }
        return res;
    }

    void search(int n, int curn) {
        int nextn = curn * 10;
        for (int i = 0; i < 10; i++) {
            int tmp = nextn + i;
            if (tmp <= n) {
                res.push_back(tmp);
                search(n, tmp);
            }
            else break;
        }
    }
};
