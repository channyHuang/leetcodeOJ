class Solution {
public:
    int bestRotation(vector<int>& A) {
        len = A.size();
        if (len <= 1) return len;
        count.resize(len, 0);
        for (int i = 0; i < len; i++) {
            if (i == A[i]) {
                count[0]++;
                count[1]--;
                if (i + 1 < len) count[i + 1]++; 
            } else if (i > A[i]) {
                count[0]++;
                if (i - A[i] + 1 < len) {
                    count[i - A[i] + 1]--;
                }
                if (i + 1 < len) count[i + 1]++;
            } else if (i < A[i]) {
                if (i + 1 < len) count[i + 1]++;
                if (len - (A[i] - i) + 1 < len) count[len - (A[i] - i) + 1]--;
            }
            //output();
        }
        int res = 0;
        int sum = 0;
        int maxSum = 0;
        for (int i = 0; i < len; i++) {
            sum += count[i];
            if (sum > maxSum) {
                maxSum = sum;
                res = i;
            }
        }
        return res;
    }

    void output() {
        for (int i = 0; i < len; i++) {
            cout << count[i] << " ";
        }
        cout << endl;
    }
private:
    int len;
    vector<int> count;
};
