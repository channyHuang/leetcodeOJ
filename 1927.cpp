class Solution {
public:
    bool sumGame(string num) {
        int len = num.length();
        int halflen = (len >> 1);
        int left = 0, right = 0;
        int leftcount = 0, rightcount = 0;
        for (int i = 0; i < halflen; ++i) {
            if (num[i] == '?') leftcount++;
            else left += num[i] - '0';
        }
        for (int i = halflen; i < len; ++i) {
            if (num[i] == '?') rightcount++;
            else right += num[i] - '0';
        }
        if (left >= right) {
            left -= right;
            right = 0;
        }
        else {
            right -= left;
            left = 0;
        }

        return calc(left, right, leftcount, rightcount);
    }

    bool calc(int left, int right, int leftcount, int rightcount) {
		if (leftcount == 0 && rightcount == 0) return (left != right);
		if ((leftcount + rightcount) % 2 == 1) return true;
		// (leftcount + rightcount) % 2 == 0
		if (leftcount == rightcount) {
			if (left == right) return false;
			return true;
		}
        if (((left - right) * 2) == 9 * (rightcount - leftcount)) return false;
        return true;
    }
};
