class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> res;
		int len = arr.size();
		if (len <= 1) return true;
		map<int, int>::iterator itr;
		for (int i = 0; i < len; i++) {
			itr = res.find(arr[i]);
			if (itr != res.end()) {
				itr->second++;
			} else {
				res.insert(pair<int, int>(arr[i], 1));
			}
		}
		vector<int> count;
		int colen = 0;
		for (itr = res.begin(); itr != res.end(); itr++) {
			for (int i = 0; i < colen; i++) {
				if (count[i] == itr->second) return false;
			}
			count.push_back(itr->second);
            colen++;
		}
		return true;
    }
};
