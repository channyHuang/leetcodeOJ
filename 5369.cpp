class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int len = rating.size();
        if (len < 3) return 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (rating[i] == rating[j]) continue;
                if (rating[i] > rating[j]) {
                    for (int k = j + 1; k < len; k++) {
                        if (rating[j] > rating[k]) res++;
                    }
                } else {
                    for (int k = j + 1; k < len; k++) {
                        if (rating[j] < rating[k]) res++;
                    }
                }
            }
        }
        return res;
    }
};
