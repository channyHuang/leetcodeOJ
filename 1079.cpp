class Solution {
public:
    int res;

    int numTilePossibilities(string tiles) {
        int len = tiles.length();
        int count[len];
        memset(count, 0, sizeof(count));
        char nums[len];
        nums[0] = tiles[0];
        count[0] = 1;
        int pos = 1;
        for (int i = 1, j; i < len; i++) {
            for (j = 0; j < pos; j++) {
                if (nums[j] == tiles[i]) break;
            }
            if (j < pos) count[j]++;
            else {
                nums[j] = tiles[i];
                count[j]++;
                pos++;
            }
        }
        res = pos;
        string str = tiles;
        for (int i = 0; i < pos; i++) {
            str[0] = nums[i];
            count[i]--;
            search(count, nums, pos, len, str, 1);
            count[i]++;
        }
        return res;
    }

    void search(int count[], char nums[], int& pos, int& len, string& str, int curPos) {
        if (curPos >= len) return;
        for (int i = 0; i < pos; i++) {
            if (count[i]) {
                str[curPos] = nums[i];
                res++;
                count[i]--;
                search(count, nums, pos, len, str, curPos + 1);
                count[i]++;
            }
        }
    }
};
