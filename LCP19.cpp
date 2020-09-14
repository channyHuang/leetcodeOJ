class Solution {
public:
    int minimumOperations(string leaves) {
        int len = leaves.size();
        long long res = len;
        int odd = 0;
        if (leaves[0] != 'r') {
            odd++;
            leaves[0] = 'r';
        }
        if (leaves[len - 1] != 'r') {
            odd++;
            leaves[len - 1] = 'r';
        }
        vector<int> reds(len + 1, 0);
        vector<pair<int, int>> fun(len + 1, make_pair(0, 0));
        //[0, i), [j, len)
        //(i - reds[i]) + (reds[j] - reds[i]) + (len - 1 - j - (reds[len] - reds[j]))
        reds[0] = 0;
        fun[0].first = INT_MAX;
        for (int i = 1; i <= len; i++) {
            reds[i] = reds[i - 1];
            if (leaves[i - 1] == 'r') {
                reds[i]++;
            } 
            if (i <= len - 2) fun[i] = make_pair(i - (reds[i] << 1), i);
            else fun[i] = fun[i - 1];
            if (fun[i].first > fun[i - 1].first) fun[i] = fun[i - 1];
        }
        /*
        for (int i = 0; i <= len; i++) {
            cout << i << " " << reds[i] << endl;
            cout << fun[i].first << " " << fun[i].second << endl;
        }*/

        for (int j = len - 1; j > 1; j--) {
            int i = fun[j - 1].second;
            long long tmp = fun[j - 1].first + reds[j] + len - j - reds[len] + reds[j];
            //cout << i << " " << j << " " << tmp << endl;
            if (tmp < res) {
                res = tmp;
                //cout << i << " " << j << endl;
            }
        }
        return res + odd;
    }
};
