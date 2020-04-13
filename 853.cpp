class Solution {
public:
    class Node {
    public:
        int pos;
        int speed;
        Node (int _p = 0, int _s = 0) {
            pos = _p;
            speed = _s;
        }
    };

    static bool cmp(Node& a, Node& b) {
        return a.pos < b.pos;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        if (len <= 1) return len;
        vector<Node> nodes;
        for (int i = 0; i < len; i++) {
            nodes.push_back(Node(position[i], speed[i]));
        }
        sort(nodes.begin(), nodes.end(), cmp);
        double time = (target - nodes[len - 1].pos) * 1.0 / nodes[len - 1].speed;
        int res = 1;
        for (int i = len - 2; i >= 0; i--) {
            double ltime = (target - nodes[i].pos) * 1.0 / nodes[i].speed;
            if (ltime <= time) continue;
            else {
                time = ltime;
                res++;
            }
        }
        return res;
    }
};
