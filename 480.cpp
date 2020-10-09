class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<double> res;
        if (k == 1 || len == 1) {
            for (int i = 0; i < len; i++) res.push_back(nums[i]);
            return res;
        }
        sets.clear();

        for (int i = 0; i < k; i++) {
            sets.insert(nums[i]);
        }

        int dist = (k & 1) ? (k >> 1) : ((k >> 1) - 1);
        itr = sets.begin();
        while (distance(sets.begin(), itr) < dist) itr++;
        if (k & 1) {
            res.push_back(*itr);
        } else {
            multiset<double>::iterator nitr = itr;
            nitr++;
            res.push_back((*itr + *nitr) / 2.0);
        }

        for (int i = k; i < len; i++) {
            sets.insert(nums[i]);
            multiset<double>::iterator nitr = sets.find(nums[i - k]);
            if (nitr == itr) itr++;
            sets.erase(nitr);

            while (distance(sets.begin(), itr) > dist) itr--;
            while (distance(sets.begin(), itr) < dist) itr++;

            if (0) {
                for (nitr = sets.begin(); nitr != sets.end(); nitr++) {
                    cout << (*nitr) << " ";
                }
                cout << endl;
            }

            if (k & 1) {
                res.push_back(*itr);
            } else {
                nitr = itr;
                nitr++;
                res.push_back((*itr + *nitr) / 2.0);
            }
        }

        if (1) {
            cout << res.size() << endl;
            for (int i = 0; i < res.size(); i++) {
                cout << res[i] << " ";
            }
            cout << endl;
        }

        return res;
    }

private:
    multiset<double> sets;
    multiset<double>::iterator itr;
};
