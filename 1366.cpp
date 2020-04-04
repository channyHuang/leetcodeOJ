class Solution {
public:
    class Node {
    public:
        int idx;
        vector<int> vote;
        Node(int _idx = 0) {
            idx = _idx;
            vote.resize(26);
        }
    };

    string rankTeams(vector<string>& votes) {
        int len = votes.size();
        int num = votes[0].length();
        if (len == 1) return votes[0];
        vector<Node> nodes;
        for (int i = 0; i < 26; i++) {
            nodes.push_back(Node(i));
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < num; j++) {
                nodes[votes[i][j] - 'A'].vote[j]++;
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        string res = votes[0];
        for (int i = 0; i < num; i++) {
            res[i] = nodes[i].idx + 'A';
        }
        return res;
    }

    static bool cmp(const Node& a, const Node& b) {
        for (int i = 0; i < 26; i++) {
            if (a.vote[i] != b.vote[i]) return a.vote[i] > b.vote[i];
        }
        return a.idx < b.idx;
    }
};
