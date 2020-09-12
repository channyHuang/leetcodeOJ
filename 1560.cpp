class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int len = rounds.size();
        vector<int> count(n, 0);
        count[rounds[0] - 1]++;
        for (int i = 1; i < len; i++) {
            int dist = ((rounds[i] - rounds[i - 1]) + n) % n;
            for (int j = 1; j <= dist; j++) {
                count[(rounds[i - 1] - 1 + j + n) % n]++;
            }
        }
        /*
        for (int i = 0; i < n; i++) {
            cout << count[i] << " ";
        }
        cout << endl;*/
        vector<int> res;
        int maxn = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] == maxn) {
                res.push_back(i + 1);
            } else if (count[i] > maxn) {
                maxn = count[i];
                res.clear();
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
