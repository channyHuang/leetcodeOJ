class Solution {
public:
    class Node {
    public:
        int value;
        int row;
        int col;

        Node (int _value = 0, int _row = 0, int _col = 0) {
            value = _value;
            row = _row;
            col = _col;
        }

        bool operator < (const Node& a) const {
            if (value == a.value) {
                return row > a.row;
            }
            return value > a.value;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int nlen = nums.size();
        priority_queue<Node, vector<Node>, less<Node>> qu;
        int maxn = nums[0][0];
        for (int i = 0; i < nlen; i++) {
            qu.push(Node(nums[i][0], i, 0));
            maxn = max(maxn, nums[i][0]);
        }
        vector<int> res(2, 0);
        res[1] = INT_MAX;
        while (1) {
            Node cur = qu.top();
            //cout << cur.value << " " << cur.row << " " << cur.col << endl;
            qu.pop();

            if (maxn - cur.value < res[1] - res[0]) {
                res[1] = maxn;
                res[0] = cur.value;
            }

            if (cur.col >= nums[cur.row].size() - 1) {
                break;
            }
            qu.push(Node(nums[cur.row][cur.col + 1], cur.row, cur.col + 1));
            maxn = max(maxn, nums[cur.row][cur.col + 1]);
        }
        return res;
    }
};
