class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		if (start == destination) return 0;
        int len = distance.size();
		/*long long dis[len][len + 1] = {0};
		for (int i = 0; i < len; i++) {
			dis[i][i + 1] = distance[i];
			for (int j = i + 2; j < len + 1; j++) {
				dis[i][j] = dis[i][j - 1] + distance[j - 1];
			}
		}
		long long sum = dis[0][len];//one circle
		long long res = 0;
		if (start < destination) res = dis[start][destination];
		else res = dis[destination][start];
		return sum - res > res ? res : sum - res;*/
		if (start > destination) {
			int tmp = start;
			start = destination;
			destination = tmp;
		}
		long long resa = 0, resb = 0;
		for (int i = 0; i < len; i++) {
			if (i >= start && i < destination) resa += distance[i];
			else resb += distance[i];
		}
		return resa < resb ? resa : resb;
    }
};
