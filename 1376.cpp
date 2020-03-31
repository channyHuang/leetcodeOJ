class Solution {
public:
    class Node {
    public:
        vector<int> folowers;
        int time;
        Node() {
            folowers.clear();
            time = 0;
        }
    };

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n == 1) return 0;
        Node nodes[n];
        int res = informTime[headID];
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1) continue;
            nodes[manager[i]].folowers.push_back(i);
        }
        queue<int> index;
        for (int i = 0; i < nodes[headID].folowers.size(); i++) {
            nodes[nodes[headID].folowers[i]].time = informTime[headID];
            index.push(nodes[headID].folowers[i]);
        }
        while (!index.empty()) {
            int curIdx = index.front();
            index.pop();
            if (res < nodes[curIdx].time) res = nodes[curIdx].time;
            for (int i = 0; i < nodes[curIdx].folowers.size(); i++) {
                nodes[nodes[curIdx].folowers[i]].time = nodes[curIdx].time + informTime[curIdx];
                index.push(nodes[curIdx].folowers[i]);
            }
        }
        return res;
    }
};
