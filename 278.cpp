// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return find(1, n);
    }

    int find(int stPos, int endPos) {
        if (stPos >= endPos) return endPos;
        //int midPos = (stPos + endPos) / 2;
        int midPos = stPos / 2 + endPos / 2;
        if (stPos % 2 && endPos % 2) midPos += 1;
        if (isBadVersion(midPos)) return find(stPos, midPos);
        else return find(midPos + 1, endPos);
    }
};
