class Solution {
public:
    class Node {
    public:
        int val;
        int pre;
        int next;
        Node(int _val = 0) {
            val = _val;
            pre = -1;
            next = -1;
        }
    };

    vector<int> processQueries(vector<int>& queries, int m) {
        int len = queries.size();
        int head;
        vector<int> res;
        Node nodes[1005];
        for (int i = 1; i <= m; i++) {
            nodes[i] = Node(i);
            if (i > 1) nodes[i].pre = i - 1;
            if (i < m) nodes[i].next = i + 1;
        }
        head = 1;
        for (int i = 0; i < len; i++) {
            if (i > 0 && queries[i] == queries[i - 1]) {
                res.push_back(0);
                continue;
            } 
            int stPos = head;
            int count = 0;
            while (nodes[stPos].val != queries[i]) {
                stPos = nodes[stPos].next;
                count++;
            }
            res.push_back(count);

            if (nodes[stPos].pre == -1) continue;
            nodes[nodes[stPos].pre].next = nodes[stPos].next;
            if (nodes[stPos].next != -1) nodes[nodes[stPos].next].pre = nodes[stPos].pre;
            nodes[head].pre = stPos;
            nodes[stPos].next = head;
            nodes[stPos].pre = -1;
            head = stPos;
        }
        return res;
    }
};
