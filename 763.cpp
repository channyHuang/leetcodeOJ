class Solution {
public:
    class Node {
    public:
        int stPos;
        int endPos;
        Node(int _st = 1000, int _end = 1000) {
            stPos = _st;
            endPos = _end;
        }
    };

    static bool cmp(const Node& a, const Node& b) {
        if (a.stPos == b.stPos) return a.endPos < b.endPos;
        return a.stPos < b.stPos;
    }

    vector<int> partitionLabels(string S) {
        vector<int> res;
        if (S.length() <= 0) return res;
        vector<Node> nodes;
        nodes.resize(27);
        for (int i = 0; i < S.length(); i++) {
            if (nodes[S[i] - 'a'].stPos == 1000) {
                nodes[S[i] - 'a'].stPos = i;
                nodes[S[i] - 'a'].endPos = i;
            } else {
                nodes[S[i] - 'a'].endPos = i;
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        int start = nodes[0].stPos;
        int end = nodes[0].endPos;

        for (int i = 1; i <= 26; i++) {
            if (nodes[i].stPos == 1000) {
                res.push_back(end - start + 1);
                break;
            }
            if (nodes[i].stPos > end) {
                res.push_back(end - start + 1);
                start = nodes[i].stPos;
                end = nodes[i].endPos;
            } else if (nodes[i].endPos > end) {
                end = nodes[i].endPos;
            }
        }
        return res;
    }
};
