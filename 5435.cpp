class Solution {
public:
    class Node {
    public:
        int index, in, out;
        vector<int> pre;
        vector<int> next;
        int level;
        
        Node(int _idx = 0) {
            index = _idx;
            level = -1;
            pre.clear();
            next.clear();
        }
    };
    
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        nodes.resize(n);
        int res = 0;
        int len = dependencies.size();
        for (int i = 0; i < len; i++) {
            nodes[dependencies[i][0] - 1].next.push_back(dependencies[i][1] - 1);
            nodes[dependencies[i][1] - 1].pre.push_back(dependencies[i][0] - 1);
        }
        for (int i = 0; i < n; i++) {
            nodes[i].index = i;
            nodes[i].in = nodes[i].pre.size();
            nodes[i].out = nodes[i].next.size();
        }
        for (int i = 0; i < n; i++) {
            if (nodes[i].in != 0) continue;
            searchLevel(i, 0);
        }
        
        bool used[n];
        memset(used, false, sizeof(used));
        int count = n;
        while (count) {
            //std::cout << count << std::endl;
            res++;
            sort(nodes.begin(), nodes.end(), cmp);
            for (int i = 0; i < n; i++) {
                std::cout << nodes[i].index << " " << nodes[i].in << " " << nodes[i].out << std::endl;
                for (int j = 0; j < nodes[i].next.size(); j++) {
                    std::cout << nodes[i].next[j] << " ";
                }
                std::cout << std::endl;
            }
            int tmp = k;
            for (int i = 0; i < n; i++) {
                if (nodes[i].in != 0 || tmp <= 0) break;
                if (used[nodes[i].index]) {
                    continue;
                }
                count--;
                tmp--;
                used[nodes[i].index] = true;
                for (int j = 0; j < nodes[i].next.size(); j++) {
                    if (!used[nodes[i].next[j]]) nodes[nodes[i].next[j]].in--;
                }
            }
        }
        return res;
    }
    
    static int cmpin(Node& a, Node& b) {
        return a.in < b.in;
    }
    static int cmp(Node& a, Node& b) {
        if (a.in == b.in) return a.level > b.level;
        return a.in < b.in;
    }
    
    void searchLevel(int idx, int level) {
        nodes[idx].level = level;
        for (int i = 0; i < nodes[idx].out; i++) {
            if (nodes[nodes[idx].next[i]].level < level + 1) {
                nodes[nodes[idx].next[i]].level = level + 1;
                searchLevel(nodes[idx].next[i], level + 1);
            }
        }
    }
private:
    vector<Node> nodes;
};
