class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int len = target.size();
        if (len == 1) return target[0];
        vector<int> vec(len, 0);
        vec[0] = target[0];
        int pos = 0;
        res = 0;
        for (int i = 1; i < len; i++) {
            if (vec[pos] == target[i]) continue;
            else if (vec[pos] < target[i]) {
                vec[pos + 1] = target[i];
                pos++;
            } else {
                if (pos == 0) {
                    res += (vec[pos] - target[i]);
                    vec[pos] = target[i];
                } else if (vec[pos - 1] < vec[pos]){
                    res += (vec[pos] - max(vec[pos - 1], target[i]));
                    i--;
                    pos--;
                }
            }
        } 
        while (pos >= 0) {
            res += (pos > 0 ? vec[pos] - vec[pos - 1] : vec[pos]);
            pos--;
        }
        return res;
    }
private:
    int res;
};


/*
//TLE
class Solution {
public:
    class Node {
    public:
        int value;
        int stPos;
        int endPos;
        bool valid;
        Node(int _value = 0, int _stPos = 0, int _endPos = 0) {
            value = _value;
            stPos = _stPos;
            endPos = _endPos;
            valid = true;
        }
    };

    int minNumberOperations(vector<int>& target) {
        int len = target.size();
        if (len == 1) return target[0];
        vector<Node> nodes(1, Node(target[0], 0, 0));
        pos = 0;
        for (int i = 1; i < len; i++) {
            if (target[i] == target[i - 1]) {
                nodes[pos].endPos = i;
            } else {
                nodes.push_back(Node(target[i], i, i));
                pos++;
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        pos = 0;
        res = 0;
        minNumberOperations(nodes, 0, len - 1, 0);
        cout << res << endl;
        return res;
    }

    static bool cmp(const Node& a, const Node& b) {
        if (a.value == b.value) return a.stPos < b.stPos;
        return a.value < b.value;
    }

    void minNumberOperations(vector<Node>& nodes, int stPos, int endPos, int lastMin) {
        while (pos < nodes.size() && !nodes[pos].valid) pos++;
        if (stPos > endPos) return;
        if (pos >= nodes.size()) return;
        for (int i = pos; i < nodes.size(); i++) {
            if (nodes[i].stPos < stPos || nodes[i].endPos > endPos) continue;
            res += (nodes[i].value - lastMin);
            nodes[i].valid = false;
            if (nodes[i].stPos > stPos) {
                minNumberOperations(nodes, stPos, nodes[i].stPos - 1, nodes[i].value);
            }
            if (nodes[i].endPos < endPos) {
                minNumberOperations(nodes, nodes[i].endPos + 1, endPos, nodes[i].value);
            }
            break;
        }
    }

private:
    int pos;
    int res;
};
*/

