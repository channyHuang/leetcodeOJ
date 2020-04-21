class Solution {
public:
    class Node {
    public:
        string c;
        int idx;
        int count;
        Node(string _c = "a", int _idx = 0, int _count = 0) {
            c = _c;
            idx = _idx;
            count = _count;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        string res = "d";
        vector<Node> nodes;
        nodes.push_back(Node("a", 0, a));
        nodes.push_back(Node("b", 1, b));
        nodes.push_back(Node("c", 2, c));

        int pos = 0;
        sort(nodes.begin(), nodes.end(), cmp);
        while (nodes[0].count) {
            pos = res.size() - 1;
            if (res[pos] != nodes[0].c[0]) {
                if (nodes[0].count >= 2) {
                    res += nodes[0].c;
                    res += nodes[0].c;
                    nodes[0].count -= 2;
                } else {
                    res += nodes[0].c;
                    nodes[0].count--;
                }
            } else {
                if (nodes[1].count > 0) {
                    res += nodes[1].c;
                    nodes[1].count--;
                    /*if (nodes[1].count >= 1) {                     
                        res += nodes[1].c;
                        nodes[1].count--;
                    }*/
                } else break;
            }
            sort(nodes.begin(), nodes.end(), cmp);
        }
        return res.substr(1);
    }

    static bool cmp(Node& a, Node& b) {
        if (a.count == b.count) return a.c < b.c;
        return a.count > b.count;
    }
};
