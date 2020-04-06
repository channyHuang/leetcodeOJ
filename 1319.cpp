class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if (len < n - 1) return -1;
        int con[n];
        for (int i = 0; i < n; i++) {
            con[i] = i;
        }
        int res = n;
        for (int i = 0; i < len; i++) {
            int pa = findParent(con, connections[i][0]);
            int pb = findParent(con, connections[i][1]);
            if (pa != pb) {
                con[pb] = pa;
                res--;
            }
        }
        return res - 1;
    }

    int findParent(int con[], int idx) {
        while (idx != con[idx]) idx = con[idx];
        return idx;
    }
};
