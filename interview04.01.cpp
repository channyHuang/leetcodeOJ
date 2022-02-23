class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if (start == target) return true;
        int glen = graph.size();
        unordered_map<int, unordered_set<int>> maps;
        for (int i = 0; i < glen; ++i) {
            if (graph[i][0] == graph[i][1]) continue;
            maps[graph[i][0]].insert(graph[i][1]);
        }

        unordered_set<int> used;
        used.insert(start);
        queue<int> qu;
        qu.push(start);
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();

            if (cur == target) return true;
            auto itr = maps.find(cur);
            if (itr == maps.end()) continue;
            for (auto sitr = itr->second.begin(); sitr != itr->second.end(); sitr++) {
                if (*sitr == target) return true;
                if (used.find(*sitr) != used.end()) continue;
                used.insert(*sitr);
                qu.push(*sitr);
            }
        }
        return false;
    }
};
