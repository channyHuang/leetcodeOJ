class Solution {
public:
    class Node {
    public:
        int idx;
        map<int, int> neighbor;
    };
    class quNode {
    public:
        int idx;
        int curStep;
        int fromColor;
        quNode(int _idx = 0, int _curStep = 0, int _fromColor = 0) {
            idx = _idx;
            curStep = _curStep;
            fromColor = _fromColor;
        }
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res;
        vector<int> tmpres;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        Node nodes[n];
        for (int i = 0; i < n; i++) {
            res.push_back(-1);
            tmpres.push_back(-1);
        }
        res[0] = 0;
        tmpres[0] = 0;
        for (int i = 0; i < red_edges.size(); i++) {
            nodes[red_edges[i][0]].neighbor.insert(pair<int, int>(red_edges[i][1], 1));
        }
        for (int i = 0; i < blue_edges.size(); i++) {
            map<int, int>::iterator itr = nodes[blue_edges[i][0]].neighbor.find(blue_edges[i][1]);
            if (itr != nodes[blue_edges[i][0]].neighbor.end()) itr->second = 3;
            else nodes[blue_edges[i][0]].neighbor.insert(pair<int, int>(blue_edges[i][1], 2));
        }
        queue<quNode> index;
        index.push(quNode(0, 0, 1));
        index.push(quNode(0, 0, 2));
        while (!index.empty()) {
            quNode curNode = index.front();
            index.pop();
            for (map<int, int>::iterator itr = nodes[curNode.idx].neighbor.begin(); itr != nodes[curNode.idx].neighbor.end();) {
                if (curNode.fromColor == itr->second) {
                    itr++;
                    continue;
                }
                
                if (res[itr->first] == -1) {
                    res[itr->first] = curNode.curStep + 1;
                }
                if (curNode.fromColor == 1) {
                    index.push(quNode(itr->first, curNode.curStep + 1, 2));
                    if (itr->second == 2) {
                        nodes[curNode.idx].neighbor.erase(itr++);
                        continue;
                    }
                    else itr->second = 1;
                }
                else {
                    index.push(quNode(itr->first, curNode.curStep + 1, 1));
                    if (itr->second == 1) {
                        nodes[curNode.idx].neighbor.erase(itr++);
                        continue;
                    }
                    else itr->second = 2;
                }
                itr++;
            }
        }
        return res;
    }
};
