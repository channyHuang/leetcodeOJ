class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> nodes(n, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            nodes[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int len = queries.size();
        vector<bool> res(len, false);
        for (int i = 0; i < len; i++) {
            vector<bool> searched(n, false);
            queue<int> qu;
            qu.push(queries[i][1]);
            searched[queries[i][1]] = true;
            bool finded = false;
            while (!qu.empty()) {
                int cur = qu.front();
                qu.pop();
                for (int x : nodes[cur]) {
                    if (searched[x]) continue;
                    if (x == queries[i][0]) {
                        res[i] = true;
                        finded = true;
                        break;
                    }
                    qu.push(x);
                    searched[x] = true;
                }
                if (finded) break;
            }
        }
        return res;
    }
};
