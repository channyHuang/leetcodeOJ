class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //neighbor idx, edge idx
        int res = 0;
        neighbors.resize(n, vector<pair<int, int>>());
        for (int i = 0; i < edges.size(); i++) {
            neighbors[edges[i][1]].push_back(make_pair(edges[i][0], i));
            neighbors[edges[i][0]].push_back(make_pair(edges[i][1], i));
        }
        
        parents.resize(n, make_pair(-1, 0));
        vector<bool> hasParent(n, false);
        hasParent[0] = true;
        findParent(0, hasParent);
        
        vector<bool> used(edges.size(), false);
        for (int i = 0; i < n; i++) {
            if (!hasApple[i]) continue;
            res += search(i, parents, used);
        }
        return res;
    }

    int search(int idx, vector<pair<int, int>>& parents, vector<bool>& used) {
        int parentIdx = parents[idx].first;
        int res = 0;
        while (parentIdx != -1) {
            if (used[parents[idx].second]) break;
            used[parents[idx].second] = true;
            res += 2;
            idx = parentIdx;
            parentIdx = parents[idx].first;
        }
        return res;
    }

    void findParent(int idx, vector<bool>& hasParent) {
        for (int i = 0; i < neighbors[idx].size(); i++) {
            if (hasParent[neighbors[idx][i].first]) continue;
            hasParent[neighbors[idx][i].first] = true;
            parents[neighbors[idx][i].first] = make_pair(idx, neighbors[idx][i].second);
            findParent(neighbors[idx][i].first, hasParent);
        }
    }

private:
    vector<vector<pair<int, int>>> neighbors;
    vector<pair<int, int>> parents;
};
