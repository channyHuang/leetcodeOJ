class Solution {
public:
    class Node {
    public:
        char c;
        int count;
        int lastTime;
        Node (char _c = ' ', int _count = 0, int _time = 0) {
            c = _c;
            count = _count;
            lastTime = _time;
        }
    };

    static int cmp(const void *a, const void *b) {
        if ( (*(Node *)a).count == (*(Node *)b).count) 
            return (*(Node *)b).c - (*(Node *)a).c;
        return (*(Node *)b).count - (*(Node *)a).count;
    }

    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if (len <= 0) return 0;
        Node nodes[26];
        for (int i = 0; i < 26; i++) nodes[i] = Node(i + 'A', 0, -n);
        int kindOfTask = 0;
        for (int i = 0; i < len; i++) {
            if (nodes[tasks[i] - 'A'].count == 0) kindOfTask++;
            nodes[tasks[i] - 'A'].count++;
        }
        qsort(nodes, 26, sizeof(Node), cmp);
        int maxCount = 1;
        while (maxCount < kindOfTask && nodes[maxCount].count == nodes[0].count) maxCount++;

        int res = 0;
        if (n >= kindOfTask - 1) {
            res = (nodes[0].count - 1) * (n + 1) + maxCount;
            return res;
        }
        int time = -1;
        while (nodes[0].count != 0) {
            time++;
            int pos = 0;
            while (nodes[pos].count != 0) {
                if (nodes[pos].lastTime + n < time) break;
                pos++;
            }
            if (nodes[pos].count == 0) {
                if (pos == 0) break;
                //time++;
                continue;
            }
            nodes[pos].count--;
            nodes[pos].lastTime = time;
            qsort(nodes, 26, sizeof(Node), cmp);
        }
        return time;
    }
};
