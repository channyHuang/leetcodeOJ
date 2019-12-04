/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
		int fun = customfunction.f(1, 1);
		if (fun > z) return res;
		else if (fun == z) {
			vector<int> subres;
			subres.push_back(1);
			subres.push_back(1);
			res.push_back(subres);
			return res;
		}
		int minNum = 1, maxNum = minNum + z;
		
		fun = customfunction.f(1, maxNum);
		while (fun <= z) {
			if (fun == z) {
				vector<int> subres;
				subres.push_back(1);
				subres.push_back(maxNum);
				res.push_back(subres);
				break;
			}
			maxNum += z;
			fun = customfunction.f(1, maxNum);
		}
		
		//customfunction.f(minNum, maxNum) >= z;
		for (int i = 1; i < maxNum; i++) {
			for (int j = maxNum - 1; j >= 1; j--) {
				fun = customfunction.f(i, j);
				if (fun < z) break;
				else if (fun == z) {
					vector<int> subres;
					subres.push_back(i);
					subres.push_back(j);
					res.push_back(subres);
					break;
				}
			}
		}
		return res;
    }
};
