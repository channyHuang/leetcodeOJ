class Solution {
public:
    class Node {
    public:
        int num;
        int count;
        Node(int _num = 0, int _count = 0) {
            num = _num;
            count = _count;
        }
    };

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int len = barcodes.size();
        if (len <= 2) return barcodes;
        vector<int> res;
        res.resize(len);
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(barcodes[i]);
            if (itr == maps.end()) maps.insert(pair<int, int>(barcodes[i], 1));
            else itr->second++;
        }
        int diflen = maps.size();
        vector<Node> nodes;
        nodes.resize(diflen);
        int pos = 0;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            nodes[pos++] = Node(itr->first, itr->second);
        }
        sort(nodes.begin(), nodes.end(), cmp);
        pos = 0;
        while (1) {
            if (nodes[0].count == 0) break;
            int maxCount = nodes[0].count;
            res[pos++] = nodes[0].num;
            nodes[0].count--;
            if (pos >= len) break;
            int curPos = 1;
            bool flag = false;
            while (curPos < diflen && nodes[curPos].count == maxCount) {
                if (nodes[curPos].count == 0) break;
                res[pos++] = nodes[curPos].num;
                nodes[curPos++].count--;
                flag = true;
            }
            if (flag) continue;
            res[pos++] = nodes[1].num;
            nodes[1].count--;
            mysort(nodes);
        }
        return res;
    }

    static bool cmp(const Node& a, const Node& b) {
        if (a.count == b.count) return a.num <= b.num;
        return a.count > b.count;
    }

    void mysort(vector<Node>& nodes) {
        int pos = 2;
        while (pos < nodes.size() && nodes[pos].count > nodes[pos - 1].count) {
            Node tmp = Node(nodes[pos].num, nodes[pos].count);
            nodes[pos] = Node(nodes[pos - 1].num, nodes[pos - 1].count);
            nodes[pos - 1] = Node(tmp.num, tmp.count);
            pos++;
        }
    }
};
