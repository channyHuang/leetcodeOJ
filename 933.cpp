class RecentCounter {
public:
    int last[10001];
    int pos;
    int len;

    RecentCounter() {
        len = 0;
        pos = 0;
        for (int i = 0; i < 10001; i++) last[i] = 0;
    }
    
    int ping(int t) {
        last[len++] = t;
        while (last[pos] + 3000 < t) pos++;
        return len - pos;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
