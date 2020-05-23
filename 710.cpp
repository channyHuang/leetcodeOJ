class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        blen = blacklist.size();
        len = N - blen;
        black = blacklist;
        sort(black.begin(), black.end());
    }
    
    int pick() {
        if (len == 1) return 0;
        int idx = rand() % len;
        int pos = 0;
        while (pos < blen && black[pos] <= idx) {
            idx++;
            pos++;
        }
        return idx;
    }

private:
    int len;
    vector<int> black;
    int blen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
