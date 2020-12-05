class Solution {
public:
    class Node {
    public:
        int index;
        int step;
        bool bLastBack;
        Node(int _index = 0, int _step = 1, bool _bLastBack = false) {
            index = _index;
            step = _step;
            bLastBack = _bLastBack;
        }

        bool operator > (const Node& node) const {
            if (node.step == step) {
                return index > node.index;
            }
            return step > node.step;
        }
    };

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int flen = forbidden.size();
        for (int i = 0; i < flen; i++) {
            forb.insert(forbidden[i]);
        }
        int maxn = x + a + b + 1;
        vector<int> stepFront(maxn, INT_MAX);
        vector<int> stepBack(maxn, INT_MAX);

        priority_queue<Node, vector<Node>, greater<Node> > qu;

        qu.push(Node(0, 0, true));
        stepBack[0] = 0;
        while (!qu.empty()) {
            Node node = qu.top();
            qu.pop();

            cout << node.index << " " << node.step << " " << node.bLastBack << endl;

            if (node.index == x) return node.step;
            //front
            int nindex = node.index + a;
            if (nindex >= 0 && nindex < maxn && !forbid(nindex) && stepFront[nindex] > node.step + 1) {
                stepFront[nindex] = node.step + 1;
                qu.push(Node(nindex, node.step + 1, false));
            }
            //back
            if (!node.bLastBack) {
                nindex = node.index - b;
                if (nindex >= 0 && nindex < maxn && !forbid(nindex) && stepBack[nindex] > node.step + 1) {
                    stepBack[nindex] = node.step + 1;
                    qu.push(Node(nindex, node.step + 1, true));
                }
            }
        }

        return -1;
    }

    bool forbid(int target) {
        //return false;
        return (forb.find(target) != forb.end());
    }
private:
    unordered_set<int> forb;
};
