class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) target = -target;
        if (target <= 1) return target;
        if (target == 2) return 3;
        if (target == 3) return 2;

        long long maxn = target, minn = 1, midn;
        int lastadd = 1;
        long long sum = 0, left = 0; // 1 + 2 + ... + lastadd > target, 1 + ... + lastadd + (lastadd + 1) > target
        while (minn <= maxn) {
            midn = ((minn + maxn) >> 1);
            sum = 0;
            if (midn & 1) {
                sum = ((midn + 1) >> 1) * midn;
            } else {
                sum = (midn >> 1) * (midn + 1);
            }

            if (sum == target) {
                return midn;
            }
            if (sum > target) {
                if (sum - midn == target) return midn - 1;
                if (sum - midn < target) {
                    lastadd = midn;
                    left = sum - target;
                    break;
                }
                maxn = midn - 1;
            } else {
                minn = midn + 1;
            }
        }
        if ((left & 1) == 0) return lastadd;
        if ((lastadd & 1) == 0) return lastadd + 1;
		return lastadd + 2;
    }
};
