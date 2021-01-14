class Solution {
public:
    class Node {
    public:
        int speed;
        int efficiency;
        Node(int _speed = 0, int _efficiency = 0) {
            speed = _speed;
            efficiency = _efficiency;
        }
    };

    static bool cmp(Node& a, Node& b) {
        if (a.efficiency == b.efficiency) {
            return a.speed > b.speed;
        }
        return a.efficiency > b.efficiency;
    }

    struct cmp2 {
        bool operator () (Node& a, Node& b) {
            if (a.speed == b.speed) {
                return a.efficiency < b.efficiency;
            }
            return a.speed > b.speed;
        }
    };

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        len = n;
        vector<Node> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(Node(speed[i], efficiency[i]));
        }
        sort(nodes.begin(), nodes.end(), cmp);
        res = (long long)nodes[0].efficiency * nodes[0].speed;
        long long sum = nodes[0].speed;
        priority_queue<Node, vector<Node>, cmp2> qu;
        qu.push(nodes[0]);
        for (int i = 1; i < n; i++) {
            long long tmpsum = sum;
            if (qu.size() < k) {
                qu.push(nodes[i]);
                sum += nodes[i].speed;

                res = max(res, nodes[i].efficiency * sum);
            } else if (qu.top().speed < nodes[i].speed) {
                sum -= qu.top().speed;
                qu.pop();
                qu.push(nodes[i]);
                sum += nodes[i].speed;

                res = max(res, nodes[i].efficiency * sum);
            } else {
                res = max(res, nodes[i].efficiency * (sum - qu.top().speed + nodes[i].speed));
            }

            //cout << i << " " << res << endl;
        }

        return res % 1000000007;
    }
private:
    int len;
    long long res;
};
