class Solution {
public:
    class Node {
    public:
        int c;
        int count;
        Node (int _c = 0, int _count = 0) {
            c = _c;
            count = _count;
        }
    };

    string reorganizeString(string S) {
        if (S.length() <= 0) return "";
        vector<Node> nodes;
        for (int i = 0; i < 26; i++) {
            nodes.push_back(Node(i, 0));
        }
        for (int i = 0; i < S.length(); i++) {
            nodes[S[i] - 'a'].count++;
        }
        sort(nodes.begin(), nodes.end(), cmp);
        string res = S;
        res[0] = nodes[0].c + 'a';
        nodes[0].count--;
        sort(nodes.begin(), nodes.end(), cmp);
        int pos = 0;
        while (1) {
            if (nodes[0].count == 0) return res;
            if (nodes[0].c + 'a' != res[pos]) {
                res[pos + 1] = nodes[0].c + 'a';
                nodes[0].count--;
                pos++;
            } else if (nodes[1].count == 0) return "";
            else {
                res[pos + 1] = nodes[1].c + 'a';
                nodes[1].count--;
                pos++;
            }
            sort(nodes.begin(), nodes.end(), cmp);
        }
        return res;
    }
    
    static bool cmp(const Node& a, const Node& b) {
        if (a.count == b.count) return a.c < b.c;
        return a.count > b.count;
    }
};
