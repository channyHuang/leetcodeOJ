class Solution {
public:
    struct Node {
        long long fixed;
        long long numerator;
        long long denominator; 
        Node(float _fixed = 0, long long _numerator = 0, long long _denominator = 1) : fixed(_fixed), numerator(_numerator), denominator(_denominator) {}
    };

    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
        unordered_map<int, vector<int>> neighbors; 
        unordered_map<int, vector<int>>::iterator itr;
        int flen = finalCnt.size(), elen = edges.size(), plen = plans.size();
        int len = flen + 1;
        vector<int> res(len, 0);
        for (int i = 0; i < elen; ++i) {
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }

        vector<Node> count(len, Node());
        count[0].numerator = 1;
        for (int i = 1; i < len; ++i) {
            count[i].fixed = finalCnt[i - 1];
        }
        for (int i = plen - 1; i >= 0; --i) {
            switch(plans[i][0]) {
            case 1:
                count[plans[i][1]].fixed *= 2;
                count[plans[i][1]].numerator *= 2;
                break;
            case 2:
                itr = neighbors.find(plans[i][1]);
                if (itr != neighbors.end()) {
                    for (int j = 0; j < itr->second.size(); ++j) {
                        addOrMinusNode(count[itr->second[j]], count[plans[i][1]], false);
                    }
                }
                break;
            case 3:
                itr = neighbors.find(plans[i][1]);
                if (itr != neighbors.end()) {
                    for (int j = 0; j < itr->second.size(); ++j) {
                        addOrMinusNode(count[itr->second[j]], count[plans[i][1]], true);
                    }
                }
                break;
            default:
                break;
            }
        }
        Node node;
        for (int i = 0; i < len; ++i) {
            addOrMinusNode(node, count[i], true);
        }
        totalNum -= node.fixed;
        long long x = totalNum * node.denominator / node.numerator;
        
        for (int i = 0; i < len; ++i) {
            res[i] = count[i].fixed + count[i].numerator * x / count[i].denominator;
        }
        return res;
    }
    // a += b
    void addOrMinusNode(Node& a, const Node& b, bool add) {
        if (add) {
            a.fixed += b.fixed;
            a.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        } else {
            a.fixed -= b.fixed;
            a.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
        }
        a.denominator *= b.denominator;
    }
};

