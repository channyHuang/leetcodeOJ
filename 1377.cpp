class Solution {
public:
    class Node {
    public:
        int step;
        vector<int> children;
        bool used;
        int from;
        int to;
        Node() {
            step = 0;
            children.clear();
            from = 1;
            to = 1;
            used = false;
        }
    };

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        int len = edges.size();
        nodes.resize(n + 1);
        if (n == 1) return 1.0;
        for (int i = 0; i < len; i++) {
            nodes[edges[i][0]].children.push_back(edges[i][1]);
            nodes[edges[i][1]].children.push_back(edges[i][0]);
        }
        nodes[1].used = true;
        search(1, t, target);
        if (nodes[target].step != 0 && nodes[target].step <= t) return nodes[target].from * 1.0 / nodes[target].to;
        return 0;
    }

    void search(int idx, int t, int target) {
        int len = nodes[idx].children.size();
        if (nodes[idx].step > t) return;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (nodes[nodes[idx].children[i]].used) continue;
            count++;
        }
        for (int i = 0; i < len; i++) {
            if (nodes[nodes[idx].children[i]].used) continue;
            nodes[nodes[idx].children[i]].to = count * nodes[idx].to;
            nodes[nodes[idx].children[i]].step = nodes[idx].step + 1;
            if (nodes[idx].children[i] == target && nodes[target].step == t) break;
            nodes[nodes[idx].children[i]].used = true;
            nodes[idx].from = 0;
            search(nodes[idx].children[i], t, target); 
        }
    }

private:
    vector<Node> nodes;
};
