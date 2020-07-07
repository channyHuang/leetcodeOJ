class Solution {
public:
    string minInteger(string num, int k) {
        int len = num.length();
        string res;
        if (k >= len * (len - 1) / 2) {
            res = num;
            sort(res.begin(), res.end());
            return res;
        }

        vector<queue<int>> index(10, queue<int>());
        for (int i = 0; i < num.length(); i++) {
            index[num[i] - '0'].push(i + 1);
        }

        maxlen = len * 4 + 1;
        tree.clear();
        tree.resize(maxlen, 0);
        int pos = 0;
        while (k && pos < len) {
            if (num[pos] == ' ') {
                pos++;
                continue;
            }
            //cout << "k = " << k << ", pos = " << pos << endl;
            //find the minimum one to swap
            int i;
            for (i = 0; i < 10; i++) {
                if (index[i].empty() || num[pos] <= num[index[i].front() - 1]) continue;
                //cout << "i = " << i << ", index[i].front = " << index[i].front() << ", preSum(index[i].front()) = " << preSum(index[i].front()) << endl;
                if (index[i].front() - 1 <= k + preSum(index[i].front())) {
                    res.append(num.substr(index[i].front() - 1, 1));
                    num[index[i].front() - 1] = ' ';
                    k -= (index[i].front() - 1 - preSum(index[i].front()));

                    //cout << "res = " << res << ", k = " << k << endl;
                    add(index[i].front(), 1);
                    index[i].pop();
                    break;
                }
            }
            if (i >= 10) {
                res.append(num.substr(pos, 1));
                add(index[num[pos] - '0'].front(), 1);
                index[num[pos] - '0'].pop();
                pos++;
            }
            //cout << "res = " << res << endl;
        }
        for (int i = pos; i < len; i++) {
            if (num[i] != ' ') res.append(num.substr(i, 1));
        }
        return res;
    }

    //before index i, how many has been used
    int preSum(int i) {
        int res = 0;
        while (i) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }

    void add(int i, int val) {
        if (i <= 0) return;
        while (i < maxlen) {
            tree[i] += val;
            i += lowbit(i);
        }
    }

    int lowbit(int x) {
        return x & (-x);
    }

private:
    vector<int> tree;
    int maxlen;
};
