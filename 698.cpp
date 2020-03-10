class Solution {
public:
    bool flag;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int len = nums.size();
        //sort(nums.begin(), nums.end());
        int total = nums[0], sum = 0;
        int maxn = nums[0];
        for (int i = 1; i < len; i++) {
            total += nums[i];
            if (maxn < nums[i]) maxn = nums[i];
        }
        if (total % k) return false;
        sum = total / k;
        if (maxn > sum) return false;
        vector<int> status;
        int maxStatus = (1 << len);
        for (int i = 1; i < maxStatus; i++) {
            int tmp = 0;
            int j = 0;
            int tmpi = i;
            while (tmpi) {
                if (tmpi & 1) {
                    tmp += nums[j];
                    if (tmp > sum) break;
                }
                j++;
                tmpi >>= 1;
            }
            if (tmp == sum) status.push_back(i);
        }

        int stlen = status.size();
        if (stlen < k) return false;
        flag = false;
        search(nums, status, k, 0, 0);
        return flag;
    }

    void search(vector<int>& nums, vector<int>& status, int k, int curStatus, int curPos) {
        if (curPos >= k) {
            if (curStatus == (1 << nums.size()) - 1) flag = true;
            return;
        }
        if (flag) return;
        for (int i = 0; i < status.size(); i++) {
            if (status[i] & curStatus) continue;
            search(nums, status, k, curStatus | status[i], curPos + 1);
            if (flag) return;
        }
    }
};

/*TLE
class Solution {
public:
    bool flag = false;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        flag = false;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int total = 0, sum = 0;
        for (int i = 0; i < len; i++) total += nums[i];
        if (total % k) return false;
        sum = total / k;
        if (nums[len - 1] > sum) return false;
        vector<bool> used;
        used.resize(len);
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] == sum) used[i] = true;
            else break;
        }
        
        int pos = len - 1;
        while (pos >= 0 && used[pos]) pos--;
        if (pos < 0) return true;
        used[pos] = true;
        int curSum = nums[pos];
        searchUsed(nums, used, sum, curSum);

        return flag;
    }

    void searchUsed(vector<int>& nums, vector<bool>& used, int sum, int curSum) {
        if (curSum == sum) {
            int i = 0;
            for (i = nums.size() - 1; i >= 0; i--) {
                if (used[i]) continue;
                else break;
            }
            if (i < 0) {
                flag = true;
                return;
            }
            searchUsed(nums, used, sum, 0);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (flag) return;
            if (used[i] || curSum + nums[i] > sum) continue;
            used[i] = true;
            searchUsed(nums, used, sum, curSum + nums[i]);
            used[i] = false;
        }
    }
};
*/
