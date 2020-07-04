class Solution {
public:
    class Node {
    public:
        int index;
        int step;
        Node (int idx, int _step) {
            index = idx;
            step = _step;
        }
    };

    bool canCross(vector<int>& stones) {
        int len = stones.size();
        if (stones[1] != 1) return false;
        int target = stones[len - 1];
        if (len == 2 || target <= len) return true;
        map<int, set<int>> maps;
        map<int, set<int>>::iterator itr;
        for (int i = 1; i < len; i++) {
            set<int> sets;
            if (i == 1) sets.insert(1);
            maps.insert(pair<int, set<int>>(stones[i], sets));
        }
        for (int i = 1; i < len; i++) {
            itr = maps.find(stones[i]);
            if (itr == maps.end()) continue;
            for (set<int>::iterator setitr = itr->second.begin(); setitr != itr->second.end(); setitr++) {
                for (int next = stones[i] + *setitr - 1; next <= stones[i] + *setitr + 1; next++)
                {
                    if (next <= 0) continue;
                    map<int, set<int>>::iterator tmpitr = maps.find(next);
                    if (tmpitr != maps.end()) maps[next].insert(next - stones[i]);
                }
            }
        }
        itr = maps.find(stones[len - 1]);
        if (itr->second.size()) return true;
        return false;
    }
};
