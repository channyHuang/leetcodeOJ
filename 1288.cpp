class Solution {
public:
    class Node {
    public:
        int x;
        int y;
        Node(int _x = 0, int _y = 0) {
            x = _x;
            y = _y;
        }
    };

    static int cmp(const void *a, const void *b) {
        if ((*(Node *)a).x == (*(Node *)b).x) {
            return (*(Node *)a).y - (*(Node *)b).y;
        }
        return (*(Node *)a).x - (*(Node *)b).x;
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        Node interval[len];
        
        for (int i = 0; i < len; i++) {
            interval[i] = Node(intervals[i][0], intervals[i][1]);
        }
        qsort(interval, len, sizeof(interval[0]), cmp);

        int res = 0;
        bool del[len] = {0};
        memset(del, false, len);
        for (int i = 1; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (del[j]) continue;
                if (interval[j].y < interval[i].y) break;
                
                del[i] = true;
                res++;
                break;
            }
        }
        return len - res;
    }
};
