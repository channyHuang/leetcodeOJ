class Solution {
public:
    int res;

    int countArrangement(int N) {
        res = 0;
        int used[N + 2] = {0};
        
        search(N, used, 1);
        return res;
    }

    void search(int N, int used[], int pos) {
        if (pos > N) {
            res++;
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (used[i]) continue;
            if (i % pos == 0 || pos % i == 0) {
                used[i] = true;
                search(N, used, pos + 1);
                used[i] = false;
            }
        }
    }
};
