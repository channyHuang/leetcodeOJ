class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
		int len = arr.size();
		queue<int> qu;
        for (int i = 0; i < len; i++) {
			if (qu.empty()) {
				if (arr[i] == 0) {
					if (i == len - 1) break;
					qu.push(arr[i + 1]);
					arr[i + 1] = 0;
					i++;
				} else {
					continue;
				}
			} else {
				qu.push(arr[i]);
				arr[i] = qu.front();
				qu.pop();
				if (arr[i] == 0) {
					if (i == len - 1) break;
					qu.push(arr[i + 1]);
					arr[i + 1] = 0;
					i++;
				}
			}
		}
    }
};
