#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
		int len = s.length();
		vector<int> res(len, 0);
		int r, c;
		for (int i = 0, j; i < len; ++i) {
			r = startPos[0], c = startPos[1];
			for (j = i; j < len; ++j) {
				switch (s[j]) {
				case 'L':
					c--;
					break;
				case 'R':
					c++;
					break;
				case 'U':
					r--;
					break;
				case 'D':
					r++;
					break;
				default:
					break;
				}

				if (r < 0 || r >= n || c < 0 || c >= n) {
					res[i] = (j - i);
					break;
				}
			}
			if (j >= len) {
				res[i] = (j - i);
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	{
		vector<int> startPos = {0, 1};
		auto res = s.executeInstructions(3, startPos, "RRDDLU");
		for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
		cout << endl;
	}
	{
		vector<int> startPos = { 1, 1 };
		auto res = s.executeInstructions(2, startPos, "LURD");
		for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
		cout << endl; 
	}
	{
		vector<int> startPos = { 0, 0 };
		auto res = s.executeInstructions(1, startPos, "LRUD");
		for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
