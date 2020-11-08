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

    static bool cmp(const Node& a, const Node& b) {
        if (a.count == b.count) return a.num > b.num;
        return a.count < b.count;
    }

    vector<int> frequencySort(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            unordered_map<int, int>::iterator itr = maps.find(nums[i]);
            if (itr == maps.end()) {
                maps[nums[i]] = 1;
            } else {
                itr->second++;
            }
        }
        vector<Node> vec;
        vector<int> res;

        for (unordered_map<int, int>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            vec.push_back(Node(itr->first, itr->second));
        }
        sort(vec.begin(), vec.end(), cmp);

        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].count; j++) {
                res.push_back(vec[i].num);
            }
        }
        return res;
    }

private:
    unordered_map<int, int> maps;
};
