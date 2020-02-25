class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bits = calcBits(arr);
        int len = bits.size();
        for (int i = 1; i < len; i++) {
            for (int j = i; j >= 1; j--) {
                if ((bits[j] < bits[j - 1]) || ((bits[j] == bits[j - 1]) && (arr[j] < arr[j - 1])) ) {
                    int tmp = bits[j];
                    bits[j] = bits[j - 1];
                    bits[j - 1] = tmp;
                    tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                }
                else break;
            }
        }
        return arr;
    }

    vector<int> calcBits(vector<int>& arr) {
        int len = arr.size();
        vector<int> res;
        res.resize(len);
        for (int i = 0; i < len; i++) {
            int tmp = arr[i];
            while (tmp) {
                tmp &= (tmp - 1);
                res[i]++;
            }
            
        }
        return res;
    }
};