class Solution {
public:
    class Node {
    public:
        int index;
        vector<int> to;
        int incnt;
        Node(int _idx = 0) {
            index = _idx;
            to.clear();
            incnt = 0;
        }
    };

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            nodes.push_back(Node(i));
            vec.push_back(make_pair(i, 0));
        }
        vector<int> res;
        int len = edges.size();
        
        for (int i = 0; i < len; i++) {
            nodes[edges[i][0]].to.push_back(edges[i][1]);
            nodes[edges[i][1]].incnt++;
            vec[edges[i][1]].second++;
        }
        sort(vec.begin(), vec.end(), cmp);
        /*
        for (int i = 0; i < n; i++) {
            cout << "-" << nodes[i].index << " ";
            for (int j = 0; j < nodes[i].to.size(); j++) {
                cout << nodes[i].to[j] << " ";
            }
            cout << endl;
        }*/

        vector<bool> used(n, false);
        for (int i = 0; i < n; i++) {           
            if (used[vec[i].first]) continue;
            res.push_back(vec[i].first);
            search(vec[i].first, used);
        }
        return res;
    }

    void search(int idx, vector<bool>& used) {
        /*
        cout << idx << endl;
        for (int i = 0; i < used.size(); i++) {
            cout << used[i] << " ";
        }
        cout << endl;*/
        used[idx] = true;
        for (int i = 0; i < nodes[idx].to.size(); i++) {
            if (used[nodes[idx].to[i]]) continue;
            search(nodes[idx].to[i], used);
        }
    }

    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
private:
    vector<Node> nodes;
};
