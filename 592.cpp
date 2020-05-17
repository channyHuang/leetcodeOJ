class Solution {
public:
    class Node {
    public:
        int up;
        int down;
        bool positive;

        Node(int _up = 0, int _down = 1, bool _positive = true) {
            up = _up;
            down = _down;
            positive = _positive;
        }
    };

    string fractionAddition(string expression) {
        Node root = Node(0, 1);
        Node cur = Node(0, 1);
        int tmp = 0;
        string res;
        if (expression[0] != '-') expression = "+" + expression;
        for (int i = 0; i <= expression.length(); i++) {
            if (i == expression.length() || expression[i] == '+' || expression[i] == '-') {
                if (tmp == 0) tmp = 1;
                cur.down = tmp;
                calc(root, cur);
                if (i == expression.length()) break;
                cur.positive = (expression[i] == '+' ? true : false);
                tmp = 0;
                continue;
            }
            if (expression[i] == '/') {
                cur.up = tmp; 
                tmp = 0;
                continue;
            }
            tmp = tmp * 10 + expression[i] - '0';
        }
        if (root.up == 0) return "0/1";
        tmp = maxFactor(root.up, root.down);
        if (tmp > 1) {
            root.up /= tmp;
            root.down /= tmp;
        }
        res = (root.positive ? "" : "-") + to_string(root.up) + "/" + to_string(root.down);
        return res;
    }

    void calc(Node &a, Node &b) {
        Node r;
        int tmp = maxFactor(a.down, b.down);
        r.down = a.down * b.down / tmp;
        if (a.positive == b.positive) {
            r.up = (a.up * b.down + b.up * a.down) / tmp;
            r.positive = a.positive;
        } else {
            if (a.positive) r.up = (a.up * b.down - b.up * a.down) / tmp;
            else r.up = (b.up * a.down - a.up * b.down) / tmp;
            if (r.up < 0) {
                r.up = -r.up;
                r.positive = false;
            }
        }
        a = r;
    }

    int maxFactor(int a, int b) {
        if (a == b) return a;
        int tmp;
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        while (a) {
            tmp = b % a;
            b = a;
            a = tmp;
        }
        return b;
    }

    int minFactor(int a, int b) {
        return a * b / maxFactor(a, b);
    }
};
