class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    	int len = arr.size();
		vector<vector<int>> res;
		if (len <= 1) return res;
		sort(arr.begin(), arr.end());
		int minDis = arr[len - 1] - arr[0];
		for (int i = 1; i < len; i++) {
			if (minDis > (arr[i] - arr[i - 1])) {
				minDis = arr[i] - arr[i - 1];
				res.clear();
				vector<int> subres;
				subres.push_back(arr[i - 1]);
				subres.push_back(arr[i]);
				res.push_back(subres);
			} else if (minDis == (arr[i] - arr[i - 1])) {
				vector<int> subres;
				subres.push_back(arr[i - 1]);
				subres.push_back(arr[i]);
				res.push_back(subres);
			}
		}
		return res;
    }
};
