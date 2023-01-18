class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        struct Node {
            long long result;
            int index;
            Node(long long _result = 0, int _index = 0) : result(_result), index(_index) {}

            bool operator <(const Node& a) const {
                if (result < a.result) return true;
                else if (result > a.result) return false;
                return (index < a.index);
            }
            bool operator >(const Node& a) const {
                if (result > a.result) return true;
                else if (result < a.result) return false;
                return (index > a.index);
            }
        };

        int len = nums.size();
        vector<Node> nodes(len);
        for (int i = 0; i < len; ++i) {
            nodes[i].index = i;
            int n = nums[i];
            long long base = 1;
            if (n == 0) nodes[i].result = mapping[0];
            while (n > 0) {
                int bit = n % 10;
                nodes[i].result += (base * mapping[bit]);
                n /= 10;
                base *= 10;
            }
        }
        sort(nodes.begin(), nodes.end());
        vector<int> res(len, 0);
        for (int i = 0; i < len; ++i) {
            res[i] = nums[nodes[i].index];
        }
        return res;
    }
};
