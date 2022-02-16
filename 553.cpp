// 最终一定是
// nums[0] / (nums[1] / nums[2] / ... / nums[len - 1]) 
// 这样的格式

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        len = nums.size();
        if (len == 1) return std::to_string(nums[0]);
        if (len == 2) return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);

        vector<int> idx(len, 0);
        for (int i = 0; i < len - 2; ++i) {
            idx[i] = i + 1;
        }
        idx[len - 2] = 0;
        idx[len - 1] = len - 1;
        residx = idx;
        //search(idx, nums);

        vector<string> res;
        for (int i = 0; i < len; ++i) {
            res.push_back(to_string(nums[i]));
        }
        if (false) {
            for (int i = 0; i < len; ++i) {
                cout << residx[i] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < len - 1; ++i) {
            int next = residx[i] + 1;
            while (next < len && res[next].length() == 0) next++;
            if (next >= len) break;
            if (res[next].find_first_of('/') != std::string::npos) {
                res[next] = "(" + res[next] + ")";
            }
            res[next] = res[residx[i]] + "/" + res[next];
            res[residx[i]] = "";

            if (false) {
                for (int i = 0; i < len; ++i) {
                    cout << res[i] << " ";
                }
                cout << endl;
            }
        }
        return res[residx[len - 1]];
    }

    void search(vector<int> &idx, vector<int> &nums) {
        do {
            vector<double> num(len, 0);
            for (int x = 0; x < len; ++x) {
                num[x] = static_cast<double>(nums[x]);
            }
            int i;

            for (i = 0; i < len - 1; ++i) {
                int next = idx[i] + 1;
                while (next < len && num[next] == 0) next++;
                if (next >= len) break;
                num[next] = num[idx[i]] / num[next];
                num[idx[i]] = 0;
            }
            if (i >= len - 1) {
                if (maxn < num[idx[len - 1]]) {
                    residx = idx;
                    maxn = num[idx[len - 1]];
                }
            }
        } while(getNext(idx));
    }

    bool getNext(vector<int> &idx) {
        int pos = len - 1;
        while (pos > 0) {
            if (idx[pos] > idx[pos - 1]) {
                break;
            }
            pos--;
        }
        if (pos <= 0) return false;
        sort(idx.begin() + pos, idx.end());
        int index = pos;
        while (index < len && idx[index] < idx[pos - 1]) index++;
        int tmp = idx[index];
        idx[index] = idx[pos - 1];
        idx[pos - 1] = tmp;
        return true;
    }

private:
    int len;
    double maxn = 0;
    vector<int> residx;
};