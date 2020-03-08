class Solution {
public:
    class Node {
    public:
        char c;
        int count;
        Node (char _c = ' ', int _count = 0) {
            c = _c;
            count = _count;
        }
    };

    static bool cmp(const Node& a, const Node& b) {
        return a.count > b.count;
    }

    string frequencySort(string s) {
        string res = s;
        vector<Node> nodes;
        nodes.resize(256);
        for (int i = 0; i < s.length(); i++) {
            nodes[(unsigned char)s[i]].c = s[i];
            nodes[(unsigned char)s[i]].count++;
        }
        sort(nodes.begin(), nodes.end(), cmp);
        int pos = 0;
        for (int i = 0; i < 256; i++) {
            while (nodes[i].count) {
                res[pos++] = nodes[i].c;
                nodes[i].count--;
                if (pos >= s.length()) break;
            }
        }
        return res;
    }
};
