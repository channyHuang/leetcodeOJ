#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

//858. ���淴��

/*
����˼·������ÿ�η��䣬���������߷ֱ��ǽ��Ӧ�������߶��󽻵㼰�������ߣ��жϽ����Ƿ��ǽ���

����˼·������һ���Ƕȿ��ǣ������������߷��򲻱䣬����������ÿ�κ�ǽ�н���ʱ�����ݽ���λ�����һ����Ϸ�ת���䣬ʹ�����������ܹ�����ǰ�������ǰ��

�����߽���Ϊ����ʱ����������������ɵ��������У�x�᳤Ϊmp��y�᳤Ϊmq=kp,m��k��Ϊ����

��p��q����С�������������m��k���ٸ���m��k����ż�Լ���ȷ�������Ӧ�Ľ����index
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
