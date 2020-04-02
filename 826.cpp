class Solution {
public:
    class Node {
    public:
        int diff;
        int prof;
        Node (int _diff = 0, int _prof = 0) {
            diff = _diff;
            prof = _prof;
        }
    };

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int works = difficulty.size();
        vector<Node> nodes;
        for (int i = 0; i < works; i++) {
            nodes.push_back(Node(difficulty[i], profit[i]));
        }
        int res = 0;
        sort(nodes.begin(), nodes.end(), cmp);
        int stPos = 0;
        int endPos = nodes.size() - 1;
        sort(worker.begin(), worker.end(), greater<int>());
        for (int i = 0; i < worker.size(); i++) {
            while (endPos >= stPos && nodes[endPos].diff > worker[i]) endPos--;
            if (endPos < 0) break;
            res += nodes[endPos].prof;
            
        }
        return res;
    }

    static bool cmp(const Node& a, const Node& b) {
        if (a.prof == b.prof) return a.diff > b.diff;
        return a.prof < b.prof;
    }
};
