class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int len = arr.size();
        int tsum = arr[0];
        for (int i = 1; i < len; i++) {
            tsum += arr[i];
        }
        int diff = abs(tsum - target);      
        if (tsum <= target) return arr[len - 1];
        sort(arr.begin(), arr.end());
         int minn = arr[len - 1];
        int stPos = target / len;
        int endPos = arr[len - 1];
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            int sum = 0;
            for (int i = 0; i < len; i++) {
                if (arr[i] <= midPos) sum += arr[i];
                else sum += midPos;
            }
            if (sum == target) return midPos;
            if (diff > abs(sum - target)) {
                diff = abs(sum - target);
                minn = midPos;
            } else if (diff == abs(sum - target)) {
                minn = min(minn, midPos);
            }
            
            if (sum < target) stPos = midPos + 1;
            else endPos = midPos - 1;
        }

        return minn;
    }
};
