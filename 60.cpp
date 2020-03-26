class Solution {
public:
    string getPermutation(int n, int k) {
        count = 0;
        bool used[10];
        memset(used, 0, sizeof(used));
        vector<int> sub;
        sub.resize(n);
        res = "";
        search(n, k, used, sub, 0);
        return res;
    }

    void search(int n, int k, bool used[], vector<int>& sub, int pos) {
        if (pos >= n) {
            count++;
            if (count >= k) {
                for (int i = 0; i < pos; i++) {
                    res += to_string(sub[i]);
                }
            }
            return;
        }
        if (count >= k) return;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            used[i] = true;
            sub[pos] = i + 1;
            search(n, k, used, sub, pos + 1);
            if (count >= k) return;
            used[i] = false;
        }
    }

private:
    int count;
    string res;
};
