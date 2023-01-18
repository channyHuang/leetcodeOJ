class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> target = {1, 22, 
        122, 212, 221, 333, 
        1333, 3133, 3313, 3331, 4444, 
        14444, 22333, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555};
        
        // 6 bit
        vector<vector<int>> nums6 = {{1, 5}, {1, 2, 3}, {2, 4}, {6}};
        getTarget(nums6, target);
        // 7 bit
        vector<vector<int>> nums7 = {{1, 6}, {1, 2, 4}, {2, 5}, {3, 4}, {7}};
        getTarget(nums7, target);
        
        sort(target.begin(), target.end());

        //for (int i = 0; i < target.size(); ++i) {
        //    cout << target[i] << " ";
        //}
        //cout << endl;

        int tlen = target.size();
        for (int i = 0; i < tlen; ++i) {
            if (n < target[i]) return target[i];
        }
        return 0;
    }

    int getbit(int n) {
        if (n <= 9) return 1;
        int res = 0;
        while (n) {
            n /= 10;
            res++;
        }
        return res;
    }

    void getTarget(vector<vector<int>> nums, vector<int>& target) {
        int nlen = nums.size();
        for (int i = 0; i < nlen; ++i) {
            int val = 0;
            for (int j = 0; j < nums[i].size(); ++j) {
                for (int k = 0; k < nums[i][j]; ++k) {
                    val = val * 10 + nums[i][j];
                }
            }
            target.push_back(val);
            while (true) {
                int next = getnext(to_string(val));
                if (next > 0) {
                    target.push_back(next);
                    val = next;
                } else break;
            }
        }
    }

    int getnext(string str) {
        int len = str.length();
        int pos = len - 2;
        int minpos = len - 1;
        while (pos >= 0 && str[pos] >= str[pos + 1]) { pos--; }
        if (pos < 0) return -1;
        sort(str.begin() + pos + 1, str.end());
        int idx = pos + 1;
        while (idx < len && str[idx] <= str[pos]) idx++;
        char tmp = str[pos];
        str[pos] = str[idx];
        str[idx] = tmp;

        int val = 0;
        for (int i = 0; i < len; ++i) {
            val = val * 10 + str[i] - '0';
        }
        return val;
    }
};
