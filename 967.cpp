class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) { 
        vector<int> res;    
        if (N == 1) {
            for (int i = 0; i < 10; i++) res.push_back(i);
            return res;
        }

        int nums[10];
        for (int i = 1; i < 10; i++) {
            nums[0] = i;
            search(N, nums, K, 1);
        }
        for (set<int>::iterator itr = ressets.begin(); itr != ressets.end(); itr++) {
            res.push_back(*itr);
        }
        return res;
    }

    void search(int N, int nums[], int K, int pos) {
        if (pos >= N) {
            int num = 0;
            for (int i = 0; i < pos; i++) num = num * 10 + nums[i];
            ressets.insert(num);
            return;
        }
        if (nums[pos - 1] + K <= 9) {
            nums[pos] = nums[pos - 1] + K;
            search(N, nums, K, pos + 1);
        } 
        if (nums[pos - 1] - K >= 0) {
            nums[pos] = nums[pos - 1] - K;
            search(N, nums, K, pos + 1);
        }
    }

private:
    set<int> ressets;
};
