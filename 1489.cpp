class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(2, vector<int>());
        numOfEdge = edges.size();
        if (numOfEdge <= 0 || numOfEdge < n - 1) return res;

        for (int i = 0; i < numOfEdge; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), cmp);
        cost = searchMinCostTree(n, edges);

        if (cost == -1) return res;

        for (int i = 0; i < numOfEdge; i++) {
            int tmpCost = searchMinCostTree(n, edges, i);

            if (tmpCost < 0) {
                res[0].push_back(edges[i][3]);
            } else if (tmpCost == cost) {
                if (judgeHasMST(n, edges, i) == cost) {
                    res[1].push_back(edges[i][3]);
                }
            } else {
                res[0].push_back(edges[i][3]);
            }
        }

        return res;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[2] == b[2]) {
            return a[0] < b[0];
        }
        return a[2] < b[2];
    }

    int searchMinCostTree(int n, vector<vector<int>>& edges, int removeIdx = -1) {
        vector<int> parent(n, -1);
        int minCost = 0;
        set<int> edgeIdx;
        for (int i = 0; i < numOfEdge; i++) {
            if (i == removeIdx) continue;
            int para = findParent(parent, edges[i][0]);
            int parb = findParent(parent, edges[i][1]);

            if (para != parb) {
                edgeIdx.insert(i);
                minCost += edges[i][2];

                parent[para] += parent[parb];
                parent[parb] = para;
            }

            if (edgeIdx.size() == n -1) break;
        }

        return (edgeIdx.size() == n - 1 ? minCost : -1);
    }

    int judgeHasMST(int n, vector<vector<int>>& edges, int needIdx) {
        vector<int> parent(n, -1);
        parent[edges[needIdx][0]] += parent[edges[needIdx][1]];
        parent[edges[needIdx][1]] = edges[needIdx][0];
        int minCost = edges[needIdx][2];

        set<int> edgeIdx;
        edgeIdx.insert(needIdx);
        for (int i = 0; i < numOfEdge; i++) {
            if (i == needIdx) continue;
            int para = findParent(parent, edges[i][0]);
            int parb = findParent(parent, edges[i][1]);

            if (para != parb) {
                edgeIdx.insert(i);
                minCost += edges[i][2];

                parent[para] += parent[parb];
                parent[parb] = para;
            }

            if (edgeIdx.size() == n -1) break;
        }

        return (edgeIdx.size() == n - 1 ? minCost : -1);
    }

    int findParent(vector<int>& parent, int idx) {
        while (parent[idx] >= 0) idx = parent[idx];
        return idx;
    }

private:
    int numOfEdge;
    int cost;
};
