class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int len = nums.size();
        int half = (len >> 1);
        vector<int> res((limit << 1) + 5, 0);
        for (int i = 0; i < half; i++) {
            int A = nums[i], B = nums[len - i - 1];
            //2~limit*2
            res[2] += 2;
            res[(limit << 1) + 1] -= 2;
            //1 + min(A, B), limit + max(A, B)
            res[1 + min(A, B)] -= 1;
            res[limit + max(A, B) + 1] += 1;
            //A+B
            res[A + B] -= 1;
            res[A + B + 1] += 1;
            
            //for (int j = 0; j < res.size(); j++) {
            //    cout << res[j] << " ";
            //}
            //cout << endl;
        }
        int result = half;
        int sum = 0;
        for (int i = 2; i <= (limit << 1); i++) {
            sum += res[i];
            if (sum < result) {
                result = sum;
            }
        }
        return result;
    }
};
