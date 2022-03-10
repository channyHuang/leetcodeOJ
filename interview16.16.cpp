class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int len = array.size();
        vector<int> res = {-1, -1};
        if (len <= 2) return res;

        vector<int> maxn(len, 0);
        vector<int> minn(len, 0);
        int stpos = 0, endpos = len - 1;
        // up
        if (array[0] < array[len - 1]) {
            left2right(array, len, false, minn, maxn);
            if (array[0] != minn[0] && array[len - 1] != maxn[len - 1]) return res;
            
            while (stpos < endpos && array[stpos] <= minn[stpos + 1]) stpos++;
            if (stpos >= endpos) return res;
            while (endpos > stpos && array[endpos] >= maxn[endpos - 1]) endpos--;
        } else if (array[0] > array[len - 1]) { // down
            left2right(array, len, true, minn, maxn);
            if (array[0] != maxn[0] && array[len - 1] != minn[len - 1]) return res;

            while (stpos < endpos && array[stpos] >= maxn[stpos + 1]) stpos++;
            if (stpos >= endpos) return res;
            while (endpos > stpos && array[endpos] <= minn[endpos - 1]) endpos--;
        } else {
            left2right(array, len, false, minn, maxn);
            if (maxn[len - 1] == minn[0]) return res;
            if (array[0] != minn[0] && array[len - 1] != maxn[len - 1]) return res;

            if (minn[0] == array[0]) { // up
                while (stpos < endpos && array[stpos] <= minn[stpos + 1]) stpos++;
            } else {
                left2right(array, len, true, minn, maxn);
                while (endpos > 0 && array[endpos] >= maxn[endpos - 1]) endpos--;
            }
        }
        res[0] = stpos;
        res[1] = endpos;
        return res;
    }

    void left2right(vector<int>& array, int len, bool calcmin, vector<int>& minn, vector<int>& maxn) {
        if (calcmin) { // left 2 right minn, right 2 left maxn
            minn[0] = array[0];
            maxn[len - 1] = array[len - 1];

            for (int i = 1; i < len; ++i) {
                minn[i] = std::min(minn[i - 1], array[i]);
                maxn[len - i - 1] = std::max(maxn[len - i], array[len - i - 1]);
            }
        } else {
            maxn[0] = array[0];
            minn[len - 1] = array[len - 1];

            for (int i = 1; i < len; ++i) {
                maxn[i] = std::max(maxn[i - 1], array[i]);
                minn[len - i - 1] = std::min(minn[len - i], array[len - i - 1]);
            }
        }
    }
};
