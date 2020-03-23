class Solution {
public:
    class Node {
    public:
        int n;
        int w;
        Node(int _n = 0, int _w = 0) {
            n = _n;
            w = _w;
        }
    };

    static bool cmp(const Node &a, const Node &b) {
        if (a.w == b.w) return a.n < b.n;
        return a.w < b.w;
    }

    int getKth(int lo, int hi, int k) {
        vector<Node> nums;
        nums.resize(hi - lo + 1);
        for (int i = lo; i <= hi; i++) {
            int w = 0;
            int tmp = i;
            while (tmp != 1) {
                if (tmp & 1) tmp = tmp * 3 + 1;
                else tmp /= 2;
                w++;
            }
            nums[i - lo] = Node(i, w);
        }
        sort(nums.begin(), nums.end(), cmp);
        return nums[k - 1].n;
    }
};
