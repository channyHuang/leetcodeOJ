class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        res.clear();
        res.resize(len, 0);
        nodes.clear();
        for (int i = 0; i < len; i++) {
            nodes.push_back(Node(i, ratings[i]));
        }
        sort(nodes.begin(), nodes.end(), cmp);
        for (int i = 0; i < len; i++) {
            int pos = nodes[i].index;
            int minval = 1;
            if (pos > 0) {
                if (ratings[pos - 1] < ratings[pos] && res[pos - 1] != 0) minval = max(minval, res[pos - 1] + 1);
            }
            if (pos < len - 1) {
                if (ratings[pos + 1] < ratings[pos] && res[pos + 1] != 0) minval = max(minval, res[pos + 1] + 1);
            }
            res[pos] = minval;
        }

        return accumulate(res.begin(), res.end(), 0);
    }

    class Node {
    public:
        int index;
        int score;
        int candy;
        Node(int _index = 0, int _score = 0) {
            index = _index;
            score = _score;
        }
    };

    static bool cmp(Node& a, Node& b) {
        if (a.score == b.score) return a.index < b.index;
        return a.score < b.score;
    }

private:
    vector<int> res;
    vector<Node> nodes;
};
