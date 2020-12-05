class Solution {
public:
    struct Node {
    public:
        int index;
        int num;
        Node (int _index = 0, int _num = 0) {
            index = _index;
            num = _num;
        }
        bool operator > (const Node& node) const {
            if (num == node.num) {
                return index > node.index;
            }
            return num > node.num;
        }
    };

    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int len = nums.size();
        if (k >= len) return nums;
        priority_queue<Node, vector<Node>, greater<Node> > qu;

        for (int i = 0; i < len - k; i++) {
            Node node = Node(i, nums[i]);
            qu.push(node);
        }
        vector<int> res(k, 0);
        int stPos = -1;
        int curPos = 0;
        for (int i = len - k; i < len; i++) {
            qu.push(Node(i, nums[i]));
            
            Node node = qu.top();
            qu.pop();
            res[curPos++] = node.num;
            stPos = max(stPos, node.index);

            while (!qu.empty() && qu.top().index <= stPos) {
                qu.pop();
            }
        }
        return res;
    }
};
