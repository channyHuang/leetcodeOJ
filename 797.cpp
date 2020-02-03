class Solution {
public:
    vector<vector<int>> res;
    int n;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        res.clear();
        int path[20] = {0};
        search(path, 0, graph);
        return res;
    }

    void search(int path[20], int curPos, vector<vector<int>>& graph) {
        if (path[curPos] == n-1) {
            vector<int> subres;
            for (int i = 0; i <= curPos; i++)
                subres.push_back(path[i]);
            res.push_back(subres);
            return;
        }
        int len = graph[path[curPos]].size();
        for (int i = 0; i < len; i++) {
            path[curPos + 1] = graph[path[curPos]][i];
            search(path, curPos + 1, graph);
        }
    }
};