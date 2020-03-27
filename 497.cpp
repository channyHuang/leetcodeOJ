class Solution {
public:
    class Node {
    public:
        int x[2];
        int y[2];
        int count;
        int precount;
        Node() {}
        Node(vector<int> rest) {
            x[0] = rest[0];
            x[1] = rest[2];
            y[0] = rest[1];
            y[1] = rest[3];
            count = (y[1] - y[0] + 1) * (x[1] - x[0] + 1);
        }
    };
    vector<Node> nodes;
    int maxn;
    int len;

    Solution(vector<vector<int>>& rects) {
        len = rects.size();
        nodes.resize(len);
        for (int i = 0; i < len; i++) {
            nodes[i] = Node(rects[i]);
            if (i > 0) nodes[i].precount = nodes[i - 1].precount + nodes[i -  1].count;
        }
        maxn = nodes[len - 1].precount + nodes[len - 1].count;
    }
    
    vector<int> pick() {
        int idx = rand() % maxn + 1;
        int stPos = 0, endPos = len - 1;
        int pos;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (nodes[midPos].precount < idx && nodes[midPos].precount + nodes[midPos].count >= idx) {
                pos = midPos;
                break;
            }
            if (nodes[midPos].precount >= idx) endPos = midPos - 1;
            else stPos = midPos + 1;
        }
        idx = idx - nodes[pos].precount - 1;

        int r = idx / (nodes[pos].x[1] - nodes[pos].x[0] + 1);
        int c = idx % (nodes[pos].x[1] - nodes[pos].x[0] + 1);
        vector<int> res;
        //res.push_back(idx);
        //res.push_back(pos);
        res.push_back(nodes[pos].x[0] + c);
        res.push_back(nodes[pos].y[0] + r);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
