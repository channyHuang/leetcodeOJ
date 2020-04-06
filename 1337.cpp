class Solution {
public:
    class Node {
    public:
        int battle;
        int index;
        Node (int _battle = 0, int _index = 0) {
            battle = _battle;
            index = _index;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //m,n <= 100 , k - [1,m]
        //big root heap
        vector<int> res;
        vector<Node> nodes;
        int rows = mat.size();
        if (rows <= 0) return res;
        int cols = mat[0].size();
        if (cols <= 0) return res;
        nodes.resize(rows);

        for (int r = 0; r < rows; r++) {
            int curbat = 0;
            for (int c = 0; c < cols; c++) {
                if (!(mat[r][c] & 1)) break;
                curbat++;
            }
            nodes[r] = Node(curbat, r);
        }
        sort(nodes.begin(), nodes.end(), cmp);
        for (int i = 0; i < k; i++) {
            res.push_back(nodes[i].index);
        }
        return res;
    }

    static bool cmp(const Node& a, const Node& b) {
        if (a.battle == b.battle) return a.index < b.index;
        return a.battle < b.battle;
    }
};
