class Solution {
public:
    class Node {
    public:
        int num;
        int count;
        Node (int _num = 0, int _count = 0) {
            num = _num;
            count = _count;
        }
    };

    static bool cmp(const Node &a, const Node &b) {
        if (a.count == b.count) return a.num > b.num;
        return a.count > b.count;
    }

    int minSetSize(vector<int>& arr) {
        int len = arr.size();
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(arr[i]);
            if (itr != maps.end()) itr->second++;
            else maps.insert(pair<int, int>(arr[i], 1));
        }
        vector<Node> nodes;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            nodes.push_back(Node(itr->first, itr->second));
        }
        sort(nodes.begin(), nodes.end(), cmp);
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nodes.size(); i++) {
            res++;
            sum += nodes[i].count;
            if (sum >= len / 2 + len % 2) {
                break;
            }
        }
        return res;
    }
};
