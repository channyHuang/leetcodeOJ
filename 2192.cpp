class Solution {
public:
    struct Node {
        set<int> parents;
        set<int> children;
        set<int> allparents;
        int numPar;
        Node() : numPar(0) {}
    };
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int elen = edges.size();
        vector<Node> nodes(n);
        vector<vector<int>> res(n, vector<int>());
        for (int i = 0; i < elen; ++i) {
            nodes[edges[i][0]].children.insert(edges[i][1]);
            nodes[edges[i][1]].parents.insert(edges[i][0]);
            nodes[edges[i][1]].numPar++;
        }
        
        for (int i = 0; i < n; ++i) {
            if (nodes[i].numPar == 0)
                qu.push(i);
        }
        while (!qu.empty()) {
            auto cur = qu.front();
            qu.pop();

            search(nodes, cur);
        }
        for (int i = 0; i < n; ++i) {
            for (auto itr = nodes[i].allparents.begin(); itr != nodes[i].allparents.end(); itr++) {
                res[i].push_back(*itr);
            }
        }
        return res;
    }

    void search(vector<Node>& nodes, int idx) {
        for (auto itr = nodes[idx].children.begin(); itr != nodes[idx].children.end(); itr++) {
            nodes[*itr].allparents.insert(idx);
            nodes[*itr].numPar--;
            if (nodes[*itr].numPar == 0) {
                qu.push(*itr);
            }
            for (auto it = nodes[idx].allparents.begin(); it != nodes[idx].allparents.end(); it++) {
                nodes[*itr].allparents.insert(*it);
            }
        }
    }

private:
    queue<int> qu;
};
