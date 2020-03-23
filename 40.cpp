class Solution {
public:
    class Node {
    public:
        int num;
        int count;
        Node (int _n = 0, int _c = 0) {
            num = _n;
            count = _c;
        }
    };

    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            if (candidates[i] == target) {
                if (res.size() == 0) {
                    vector<int> sub{target};
                    res.push_back(sub);
                }
                continue;
            }
            itr = maps.find(candidates[i]);
            if (itr != maps.end()) itr->second++;
            else maps.insert(pair<int, int>(candidates[i], 1));
        }

        vector<Node> nodes;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            nodes.push_back(Node(itr->first, itr->second));
        }

        vector<int> sub;
        sub.resize(candidates.size());
        int idx = 1;
        search(target, nodes, sub, 0, 0, 0, idx);
        return res;
    }

    void search(int& target, vector<Node>& nodes, vector<int>& sub, int pos, int curSum, int nodepos, int idx) {
        if (curSum == target) {
            vector<int> subres;
            for (int i = 0; i < pos; i++) {
                subres.push_back(sub[i]);
            }
            res.push_back(subres);
            return;
        }
        if (nodepos >= nodes.size()) return;
        
        for (int i = 0; i <= nodes[nodepos].count; i++) {
            if (curSum + nodes[nodepos].num * i > target) return;
            for (int j = 0; j < i; j++) sub[pos + j] = nodes[nodepos].num;
            search(target, nodes, sub, pos + i, curSum + nodes[nodepos].num * i, nodepos + 1, idx + 1);
        }
        
    }
};
