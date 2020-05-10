class Solution {
public:
    class Node {
    public:
        int row;
        int col;
        double rate;
        int step;
        Node(int _r = 0, int _c = 0, double _rate = 1.0, int _step = 0) {
            row = _r;
            col = _c;
            rate = _rate;
            step = _step;
        }
    };

    double knightProbability(int N, int K, int r, int c) {
        queue<Node> qu;
        qu.push(Node(r, c, 1.0, 0));
        int dx[8] = {-2,-2,-1,-1,1,1,2,2};
        int dy[8] = {-1,1,-2,2,-2,2,-1,1};
        double res = 0;
        while (!qu.empty()) {
            Node node = qu.front();
            qu.pop();
            if (node.step >= K) {
                res += node.rate;
                continue;
            }
            for (int i = 0; i < 8; i++) {
                int nr = node.row + dx[i];
                int nc = node.col + dy[i];
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                Node newNode(nr, nc, node.rate / 8, node.rate + 1);
                qu.push(newNode);
            }
        }
        return res;
    }
};
