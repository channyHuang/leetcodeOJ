﻿ #include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
样例25期望输出：
[null,null,null,null,1,null,null,null,1,null,null,null,1,null,null,null,2,null,null,null,1,null,null,null,1,null,null,null,1,null,null,null,2,null,null,null,2,null,null,null,2,null,null,null,2,null,null,null,5,null,null,null,6,null,null,null,2,null,null,null,3,null,null,null,3,null,null,null,14,null,null,null,3,null,null,null,1,null,null,null,2,null,null,null,2,null,null,null,4,null,null,null,20,null,null,null,4,null,null,null,5,null,null,null,10,null,null,null,26,null,null,null,8,null,null,null,3,null,null,null,7,null,null,null,21,null,null,null,20,null,null,null,52,null,null,null,6,null,null,null,56,null,null,null,2,null,null,null,5,null,null,null,17,null,null,null,18,null,null,null,13,null,null,null,19,null,null,null,102,null,null,null,9,null,null,null,2,null,null,null,157,null,null,null,23,null,null,null,29,null,null,null,23,null,null,null,15,null,null,null,24,null,null,null,186,null,null,null,12,null,null,null,32,null,null,null,36,null,null,null,10,null,null,null,35,null,null,null...

第4个count为什么不是3? count(0,8)
其中(0,0) (8,0) (8,8)有2个，因为(8, 0)有2个
(0, 0) (9, 0) (9, 8)有1个
难道不是共3个？
*/

class DetectSquares {
public:
	DetectSquares() {
		points.clear();
		counts.clear();
		xmaps.clear();
		ymaps.clear();
		len = 0;
	}

	void add(vector<int> point) {
		auto xitr = xmaps.find(point[0]);
		if (xitr == xmaps.end()) {
			points.push_back(point);
			counts.push_back(1);
			xmaps[point[0]].insert(len);
			ymaps[point[1]].insert(len);
		}
		else {
			auto yitr = ymaps.find(point[1]);
			if (yitr == ymaps.end()) {
				points.push_back(point);
				counts.push_back(1);
				xmaps[point[0]].insert(len);
				ymaps[point[1]].insert(len);
			}
			else {
				bool repeat = false;
				for (auto nitr = xitr->second.begin(); nitr != xitr->second.end(); nitr++) {
					if (yitr->second.find(*nitr) != yitr->second.end()) {
						counts[*nitr]++;
						repeat = true;
						return;
					}
				}
				if (!repeat) {
					points.push_back(point);
					counts.push_back(1);
					xmaps[point[0]].insert(len);
					ymaps[point[1]].insert(len);
				}
			}
		}
		len++;
	}

	int count(vector<int> point) {
		int res = 0;
		for (int i = 0; i < len; ++i) {
			if (points[i][0] == point[0] || points[i][1] == point[1]) continue;
			int increase = 0;
			auto xitr = xmaps.find(points[i][0]);
			auto yitr = ymaps.find(point[1]);
			if (xitr == xmaps.end() || yitr == ymaps.end()) continue;
			for (auto nitr = xitr->second.begin(); nitr != xitr->second.end(); nitr++) {
				if (yitr->second.find(*nitr) != yitr->second.end()) {
					increase = counts[*nitr];
					break;
				}
			}
			if (increase > 0) {
				xitr = xmaps.find(point[0]);
				yitr = ymaps.find(points[i][1]);
				if (xitr == xmaps.end() || yitr == ymaps.end()) continue;
				for (auto nitr = xitr->second.begin(); nitr != xitr->second.end(); nitr++) {
					if (yitr->second.find(*nitr) != yitr->second.end()) {
						res += (increase * counts[*nitr] * counts[i]);
						break;
					}
				}
			}
		}
		return res;
	}

private:
	vector<vector<int>> points;
	vector<int> counts;
	int len;
	unordered_map<int, unordered_set<int>> xmaps, ymaps;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

int main() {
	DetectSquares s;
	{
		vector<string> ope = { "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count" };
		vector<vector<int>> points = { {5,10},{10,5},{10,10},{5,5},{3,0},{8,0},{8,5},{3,5},{9,0},{9,8},{1,8},{1,0},{0,0},{8,0},{8,8},{0,8},{1,9},{2,9},{2,10},{1,10},{7,8},{2,3},{2,8},{7,3},{9,10},{9,5},{4,5},{4,10},{0,9},{4,5},{4,9},{0,5},{1,10},{10,1},{10,10},{1,1},{10,0},{2,0},{2,8},{10,8},{7,6},{4,6},{4,9},{7,9},{10,9},{10,0},{1,0},{1,9},{0,9},{8,1},{0,1},{8,9},{3,9},{10,9},{3,2},{10,2},{3,8},{9,2},{3,2},{9,8},{0,9},{7,9},{0,2},{7,2},{10,1},{1,10},{10,10},{1,1},{6,10},{2,6},{6,6},{2,10},{6,0},{6,2},{8,2},{8,0},{6,5},{7,4},{6,4},{7,5},{2,10},{8,4},{2,4},{8,10},{2,6},{2,5},{1,5},{1,6},{10,9},{10,0},{1,9},{1,0},{0,9},{5,9},{0,4},{5,4},{3,6},{9,0},{3,0},{9,6},{0,2},{1,1},{0,1},{1,2},{1,7},{8,0},{8,7},{1,0},{2,7},{4,5},{2,5},{4,7},{6,7},{3,7},{6,4},{3,4},{10,2},{2,10},{2,2},{10,10},{10,1},{1,10},{1,1},{10,10},{2,10},{2,9},{3,9},{3,10},{10,1},{1,10},{1,1},{10,10},{10,4},{10,3},{9,4},{9,3},{6,6},{6,10},{10,6},{10,10},{9,7},{4,7},{9,2},{4,2},{2,3},{2,1},{0,3},{0,1},{2,8},{10,8},{2,0},{10,0},{8,4},{2,10},{8,10},{2,4},{0,0},{9,9},{0,9},{9,0},{5,7},{5,8},{4,7},{4,8},{10,10},{10,1},{1,1},{1,10},{6,8},{7,8},{6,9},{7,9},{4,6},{1,6},{4,3},{1,3},{10,1},{1,10},{10,10},{1,1},{7,7},{7,10},{4,7},{4,10},{0,0},{8,0},{0,8},{8,8},{3,5},{2,4},{3,4},{2,5},{0,6},{0,2},{4,2},{4,6},{5,2},{9,6},{9,2},{5,6},{1,1},{1,10},{10,10},{10,1},{7,5},{2,0},{2,5},{7,0},{1,9},{1,2},{8,2},{8,9},{3,8},{3,3},{8,3},{8,8},{3,10},{9,10},{3,4},{9,4},{0,2},{0,10},{8,10},{8,2},{9,4},{8,4},{8,5},{9,5},{9,8},{4,3},{4,8},{9,3},{4,9},{0,5},{0,9},{4,5},{1,3},{3,5},{1,5},{3,3},{0,0},{0,8},{8,0},{8,8},{2,8},{10,0},{10,8},{2,0},{8,1},{0,9},{8,9},{0,1},{4,9},{4,6},{1,9},{1,6},{0,9},{0,8},{1,9},{1,8},{5,1},{5,6},{10,1},{10,6},{9,2},{2,2},{2,9},{9,9},{5,5},{8,5},{5,8},{8,8},{8,0},{1,0},{8,7},{1,7},{8,2},{5,5},{5,2},{8,5},{6,6},{6,8},{8,6},{8,8},{2,10},{10,2},{2,2},{10,10},{1,9},{8,2},{1,2},{8,9},{7,4},{7,2},{9,4},{9,2},{1,9},{1,0},{10,0},{10,9},{2,10},{2,3},{9,10},{9,3},{10,0},{1,0},{1,9},{10,9},{8,10},{1,10},{1,3},{8,3},{0,9},{9,9},{0,0},{9,0},{7,9},{8,9},{7,8},{8,8},{3,1},{9,7},{9,1},{3,7},{5,9},{6,9},{5,8},{6,8},{0,1},{0,10},{9,10},{9,1},{8,0},{8,2},{10,2},{10,0},{8,0},{0,8},{8,8},{0,0},{6,7},{5,8},{5,7},{6,8},{0,9},{0,2},{7,9},{7,2},{5,0},{5,5},{10,0},{10,5},{1,10},{10,10},{10,1},{1,1},{9,2},{9,10},{1,2},{1,10},{1,10},{10,1},{10,10},{1,1},{9,9},{0,9},{0,0},{9,0},{9,6},{9,3},{6,3},{6,6},{10,4},{6,0},{10,0},{6,4},{6,8},{0,2},{0,8},{6,2},{7,9},{0,9},{7,2},{0,2},{9,1},{9,10},{0,10},{0,1},{10,0},{10,9},{1,9},{1,0},{1,6},{1,9},{4,9},{4,6},{0,8},{1,9},{0,9},{1,8},{1,1},{9,1},{1,9},{9,9},{2,5},{2,9},{6,5},{6,9},{7,3},{2,3},{2,8},{7,8},{9,4},{4,4},{9,9},{4,9},{4,4},{2,4},{4,2},{2,2},{0,3},{0,2},{1,3},{1,2},{10,9},{10,2},{3,2},{3,9},{5,6},{10,6},{10,1},{5,1},{9,0},{0,9},{9,9},{0,0},{5,6},{9,2},{9,6},{5,2},{3,3},{10,3},{10,10},{3,10},{2,4},{2,10},{8,4},{8,10},{4,9},{1,9},{4,6},{1,6},{1,8},{9,0},{1,0},{9,8},{10,3},{5,8},{5,3},{10,8},{8,2},{0,10},{8,10},{0,2},{9,0},{2,7},{9,7},{2,0},{0,4},{5,9},{0,9},{5,4},{5,3},{10,3},{5,8},{10,8},{6,4},{7,4},{6,5},{7,5},{9,1},{0,1},{9,10},{0,10},{5,10},{5,7},{8,7},{8,10},{8,0},{8,7},{1,7},{1,0},{1,1},{9,9},{1,9},{9,1},{3,1},{3,5},{7,5},{7,1},{5,8},{5,3},{10,8},{10,3},{0,9},{2,7},{2,9},{0,7},{9,3},{9,7},{5,3},{5,7},{0,0},{9,0},{9,9},{0,9},{6,4},{4,2},{4,4},{6,2},{1,9},{1,5},{5,5},{5,9},{7,7},{0,7},{0,0},{7,0},{1,3},{1,9},{7,3},{7,9},{0,9},{9,9},{9,0},{0,0},{1,8},{3,6},{3,8},{1,6} };
		for (int i = 0; i < ope.size(); ++i) {
			if (ope[i][0] == 'a') s.add(points[i]);
			else cout << s.count(points[i]) << endl;
		}
	}

	return 0;
}
