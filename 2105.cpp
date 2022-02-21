class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int len = plants.size();
        int stpos = 0, endpos = len - 1;
        int lefta = capacityA;
        int leftb = capacityB;
        int res = 0;
        int pos = 0;
        while (stpos <= endpos) {
            if (stpos == endpos) {
                if (lefta >= leftb) {
                    if (lefta < plants[stpos]) {
                        res++;
                    }
                } else {
                    if (leftb < plants[endpos]) {
                        res++;
                    }
                }
                break;
            }
            if (lefta < plants[pos]) {
                lefta = capacityA - plants[pos];
                res++;
            } else {
                lefta -= plants[pos];
            }
            if (leftb < plants[len - pos - 1]) {
                leftb = capacityB - plants[len - pos - 1];
                res++;
            } else {
                leftb -= plants[len - pos - 1];
            }
            stpos++;
            endpos--;
            pos++
        }
        return res;
    }
};
