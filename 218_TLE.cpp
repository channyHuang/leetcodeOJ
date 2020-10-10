class Solution {
public:
    class Node {
    public:
        int left;
        int right;
        int height;
        bool valid;
        Node(int _left = 0, int _right = 0, int _height = 0) {
            left = _left;
            right = _right;
            height = _height;
            valid = true;
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int len = buildings.size();
        if (len <= 0) return res;
        if (len == 1) {
            res.push_back(vector<int>{buildings[0][0], buildings[0][2]});
            res.push_back(vector<int>{buildings[0][1], 0});

            if (0) {
                cout << "-----" << endl;
                for (int i = 0; i < res.size(); i++) {
                    cout << res[i][0] << " " << res[i][1] << endl;
                }
            }

            return res;
        }
        vector<int> index;
        for (int i = 0; i < len; i++) {
            index.push_back(buildings[i][0]);
            index.push_back(buildings[i][1]);
        }
        sort(index.begin(), index.end());
        vector<Node> nodes;
        int pos = 0;
        for (int i = 1; i < index.size(); i++) {
            nodes.push_back(Node(index[i - 1], index[i]));
        }
        for (int i = 0; i < len; i++) {
            while (nodes[pos].right < buildings[i][0]) pos++;
            for (int j = pos; j < nodes.size(); j++) {
                if (nodes[j].left >= buildings[i][0] && nodes[j].right <= buildings[i][1]) nodes[j].height = max(nodes[j].height, buildings[i][2]);
                if (nodes[j].left > buildings[i][1]) break;
            }
        }
        int lastValid = 0;
        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i].left == nodes[lastValid].right && nodes[i].height == nodes[lastValid].height) {
                nodes[lastValid].right = nodes[i].right;
                nodes[i].valid = false;
            } else lastValid = i;
        }
        for (int i = 0; i < nodes.size(); i++) {
            if (!nodes[i].valid) continue;
            res.push_back(vector<int>{nodes[i].left, nodes[i].height});
        }
        res.push_back(vector<int>{nodes[nodes.size() - 1].right, 0});

        if (0) {
            cout << "-----" << endl;
            for (int i = 0; i < res.size(); i++) {
                cout << res[i][0] << " " << res[i][1] << endl;
            }
        }
        return res;
    }

private:
    vector<vector<int>> res;
};
