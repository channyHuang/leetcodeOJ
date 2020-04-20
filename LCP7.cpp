class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int len = relation.size();
        if (len <= 0) return 0;
        vector<int> nodes[15];
        for (int i = 0; i < len; i++) {
            nodes[relation[i][0]].push_back(relation[i][1]);
        }
        queue<int> qu[2];
        qu[0].push(0);
        int pos = 0;
        int count = 0;
        while (1) {
            while (!qu[pos].empty()) {
                int curIdx = qu[pos].front();
                qu[pos].pop();
                for (int i = 0; i < nodes[curIdx].size(); i++) {
                    qu[1 - pos].push(nodes[curIdx][i]);
                }
            }
            pos = 1 - pos;
            count++;
            if (count == k) break;
            while (!qu[1 - pos].empty()) qu[1 - pos].pop();
        }
        if (count != k) return 0;
        count = 0;
        while (!qu[pos].empty()) {
            int curIdx = qu[pos].front();
            qu[pos].pop();
            if (curIdx == n - 1) count++;
        }
        return count;
    }
};
