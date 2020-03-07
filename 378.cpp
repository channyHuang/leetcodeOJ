class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int largeHeap[k] = {0};
        int rows = matrix.size();
        int cols = matrix[0].size();
        int pos = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pos < k) {
                    largeHeap[pos] = matrix[i][j];
                    int tmp = pos;
                    int next = (tmp - 1) / 2;
                    while (next >= 0) {
                        if (largeHeap[next] < largeHeap[tmp]) {
                             int t = largeHeap[tmp];
                             largeHeap[tmp] = largeHeap[next];
                             largeHeap[next] = t;
                             tmp = next;
                             next = (tmp - 1) / 2;
                        } else break;
                    }
                    pos++;
                    continue;
                }
                if (largeHeap[0] <= matrix[i][j]) break;
                largeHeap[0] = matrix[i][j];
                int tmp = 0;
                int next = tmp * 2 + 1;
                while (next < k) {
                    if (next + 1 < k && largeHeap[next + 1] > largeHeap[next]) next++;
                    if (largeHeap[tmp] < largeHeap[next]) {
                        int t = largeHeap[tmp];
                        largeHeap[tmp] = largeHeap[next];
                        largeHeap[next] = t;
                        tmp = next;
                        next = tmp * 2 + 1;
                    } else break;
                }
            }
        }
        return largeHeap[0];
    }
};
