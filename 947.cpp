class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int len = stones.size();
        int parents[20000];
        for (int i = 0; i < 20000; i++) parents[i] = -1;
        for (int i = 0; i < len; i++) {
            int pa = findParents(parents, stones[i][0]);
            int pb = findParents(parents, stones[i][1] + 10000);
            if (pa == -1 && pb == -1) {
                parents[stones[i][1] + 10000] = parents[stones[i][0]] = stones[i][0];
            } else if (pa == -1) {
                parents[stones[i][0]] = pb;
            } else if (pb == -1) {
                parents[stones[i][1] + 10000] = pa;
            } else {
                parents[pb] = pa;
            }
        }
        int res = 0;
        for (int i = 0; i < 20000; i++) {
            if (parents[i] == i) res++;
        }
        return len - res;
    }

    int findParents(int parents[], int idx) {
        if (parents[idx] == -1) return -1;
        while (parents[idx] != idx) idx = parents[idx];
        return idx;
    }
};
