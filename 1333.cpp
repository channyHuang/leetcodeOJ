class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }

    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        vector<vector<int>> filres;
        int len = restaurants.size();
        for (int i = 0; i < len; i++) {
            if (restaurants[i][3] > maxPrice || restaurants[i][4] > maxDistance) continue;
            if (veganFriendly && !restaurants[i][2]) continue;
            filres.push_back(restaurants[i]);
        }
        //res.push_back(filres.size());
        sort(filres.begin(), filres.end(), cmp);
        for (int i = 0; i < filres.size(); i++) res.push_back(filres[i][0]);
        return res;
    }
};
