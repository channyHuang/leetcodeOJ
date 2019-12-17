class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        if (len <= 0) return 0;
        if (len < 4) return arr[0];
        int count = len / 4;
        for (int i = 0; i < len - count; i++) {
            if (arr[i] == arr[i + count]) return arr[i];
        }
        return 0;
    }
};
