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

    static bool cmp(const Node& a, const Node& b) {
        return a.count > b.count;
    }

    void swap(vector<Node>& nodes, int i, int j) {
        Node tmp = Node(nodes[i].num, nodes[i].count);
        nodes[i] = Node(nodes[j].num, nodes[j].count);
        nodes[j] = Node(tmp.num, tmp.count);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<Node> nodes;       
        vector<int> res;
        int len = nums.size();
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(nums[i]);
            if (itr == maps.end()) {
                maps.insert(pair<int, int>(nums[i], 1));
            } else itr->second++;
        }
        int pos = 0;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (pos < k) {
                nodes.push_back(Node(itr->first, itr->second));
                int cur = pos;
                pos++;
                int next = (cur - 1) / 2;
                while (next >= 0) {
                    if (nodes[next].count > nodes[cur].count) {
                        swap(nodes, next, cur);
                        cur = next;
                        next = (cur - 1) / 2;
                    } else break;
                }
            } else if (nodes[0].count >= itr->second) {
                continue;
            }
            else {
                nodes[0] = Node(itr->first, itr->second);
                int cur = 0;
                int next = cur * 2 + 1;              
                while (next < k) {
                    if (next + 1 < k && nodes[next + 1].count < nodes[next].count) next++;
                    if (nodes[cur].count > nodes[next].count) {
                        swap(nodes, cur, next);
                        cur = next;
                        next = cur * 2 + 1;
                    } else break;
                }
            }
        }   
        for (int i = 0; i < nodes.size(); i++) {
            res.push_back(nodes[i].num);
        }
        return res;
    }
};
