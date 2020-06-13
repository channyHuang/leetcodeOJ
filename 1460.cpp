class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int len = target.size();
        int count[1005];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < len; i++) {
            count[target[i]]++;
            count[arr[i]]--;
        }
        for (int i = 1; i <= 1000; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};
