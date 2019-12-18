class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        if (len < 3) return false;
        vector<int> sum;
        int totalsum = 0;
        for (int i = 0; i < len; i++) {       
            totalsum += A[i];
            sum.push_back(totalsum);
        }

        if (totalsum % 3 != 0) return false; 
        int target1 = totalsum / 3;
        bool flag = false;
        int target2 = (target1 << 1);
        for (int i = 0; i < len - 1; i++) {
            if (sum[i] == target1) flag = true;
            if (flag && sum[i] == target2) return true;
        }
        return false;
    }
};
