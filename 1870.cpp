//考点是浮点数计算精度，为避免精度误差需要把所有数化成整数计算

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
		int len = dist.size();
		if (hour < len - 1) return -1;
		sort(dist.begin(), dist.begin() + len - 1, greater<int>());
		long long minn = 1, maxn = 10000001;
		int res = maxn;
		long long ihour = llround(hour * 100);
		while (minn <= maxn) {
			long long midn = (minn + maxn) / 2;
			long long curtime = 0;
			for (int i = 0; i < len - 1; ++i) {
				if (midn >= dist[i]) {
					curtime += (len - 1 - i);
					break;
				}
				curtime += (dist[i] / midn + (dist[i] % midn == 0 ? 0 : 1));
			}

			if ((curtime * midn + dist[len - 1]) * 100 <= ihour * midn) {
				res = midn;
				maxn = midn - 1;
			} else {
				minn = midn + 1;
			}
		}
		if (res >= 10000001) return -1;
		return res;
    }
};
