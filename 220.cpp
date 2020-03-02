class Solution {
public:
    class Node {
    public:
        int num;
        int index;
        Node(int _num = 0, int _index = 0) {
            num = _num;
            index = _index;
        }
    };

    static int cmp(const void *a, const void *b) {
        if ((*(Node *)a).num == (*(Node *)b).num) {
            return ((*(Node *)a).index > (*(Node *)b).index);
        }
        return (*(Node *)a).num > (*(Node *)b).num;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if (len <= 1) return false;
        Node nodes[len];
        for (int i = 0; i < len; i++) {
            nodes[i] = Node(nums[i], i);
        }
        qsort(nodes, len, sizeof(Node), cmp);
        for (int i = 0; i < len; i++) {
            int j = i - 1;

            while (j >= 0 && (double)((double)nodes[i].num - (double)nodes[j].num) <= t) {
                if (abs(nodes[i].index - nodes[j].index) <= k) return true;
                j--;
            }
            j = i + 1;
            while (j < len && (double)((double)nodes[j].num - (double)nodes[i].num) <= t) {
                if (abs(nodes[i].index - nodes[j].index) <= k) return true;
                j++;
            }
        }
        return false;
    }
};
