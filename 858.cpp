#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

//858. 镜面反射

/*
常规思路：计算每次反射，拿入射射线分别和墙对应的四条线段求交点及反射射线，判断交点是否是角落

其它思路：从另一个角度考虑，保持入射射线方向不变，当入射射线每次和墙有交点时，根据交点位置向右或向上翻转房间，使得入射射线能够按当前方向继续前行

则当射线交点为角落时，射线与坐标轴组成的三角形中，x轴长为mp，y轴长为mq=kp,m和k均为整数

求p和q的最小公倍数即可求得m和k，再根据m和k的奇偶性即可确定交点对应的角落的index
*/








class Solution {
public:
	int mirrorReflection(int p, int q) {
		if (q == 0) return 0;
		if (std::fabs(q - p * 0.5) < 1e-6) return 2;
		if (q == p) return 1;

		int maxpq = maxFactor(p, q);
		// mp, kq
		int m = maxpq / q, k = maxpq / p;
		if ((m & 1) == 0) return 2;
		if (k & 1) return 1;
		return 0;
	}

	int minFactor(int a, int b) {
		if (a == b) return a;
		if (a == 1 || b == 1) return 1;
		if (a < b) return (minFactor(b, a));
		if (a % b == 0) return b;
		return minFactor(b, a % b);
	}

	int maxFactor(int a, int b) {
		return (a * b / minFactor(a, b));
	}
};

int main() {
	Solution s;
	cout << s.mirrorReflection(2, 1) << endl;
	cout << s.mirrorReflection(4, 1) << endl;
	cout << s.mirrorReflection(3, 2) << endl;
	return 0;
}
