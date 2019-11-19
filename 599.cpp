class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        if (list1.size() <= 0 || list2.size() <= 0) return res;
        //index sum = i
        for (int i = 0; i < list1.size() + list2.size() - 1; i++) {
            int st1 = (i < list1.size() ? i : list1.size() - 1);
            for (int x = st1; x >= 0; x--) {
                int y = i - x;
                if (y >= list2.size() || y < 0) continue;
                if (list1[x] == list2[y]) res.push_back(list1[x]);
            }
            if (res.size() > 0) break;
        }
        return res;
    }
};
