class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        alen = arr.size();
        for (int i = 0; i < alen; i++) {
            maps[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for (unordered_map<int, vector<int>>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second.size() < threshold) continue;
            int stPos = lower_bound(itr->second.begin(), itr->second.end(), left) - itr->second.begin();
            if (stPos >= itr->second.size()) continue;
            int endPos = upper_bound(itr->second.begin(), itr->second.end(), right) - itr->second.begin();
            //cout << itr->first << " " << stPos << " " << endPos << endl;
            if (threshold <= endPos - stPos) {
                return itr->first;
            }
        }
        return -1;
    }

private:
    int alen;
    unordered_map<int, vector<int>> maps;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
