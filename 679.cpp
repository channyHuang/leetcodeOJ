class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        double a = nums[0];
        double b = nums[1];
        double c = nums[2];
        double d = nums[3];

        if (judgePoint24(a, b, c, d)) return true;
        if (judgePoint24(a, c, b, d)) return true;
        if (judgePoint24(a, d, b, c)) return true;
        if (judgePoint24(b, c, a, d)) return true;
        if (judgePoint24(b, d, a, c)) return true;
        if (judgePoint24(c, d, a, b)) return true;
        return false;
    }

    bool judgePoint24(double a, double b, double c, double d) {
        if (judgePoint24(a + b, c, d, false)) return true;
        if (judgePoint24(a * b, c, d, false)) return true;
        if (judgePoint24(a - b, c, d, false)) return true;
        if (judgePoint24(b - a, c, d, false)) return true;
        if (judgePoint24(a / b, c, d, false)) return true;
        if (judgePoint24(b / a, c, d, false)) return true;
        return false;
    }

    bool judgePoint24(double a, double b, double c, bool bSort = true) {
        if (bSort) {
            if (judgePoint24(a + b, c)) return true;
            if (judgePoint24(a * b, c)) return true;
            if (judgePoint24(a - b, c)) return true;
            if (judgePoint24(b - a, c)) return true;
            if (judgePoint24(a / b, c)) return true;
            if (judgePoint24(b / a, c)) return true;
            return false;
        }
        if (judgePoint24(a, b, c)) return true;
        if (judgePoint24(a, c, b)) return true;
        if (judgePoint24(b, c, a)) return true;
        return false;
    }

    bool judgePoint24(double a, double b) {
        if (isTarget(a + b)) return true;
        if (isTarget(a * b)) return true;
        if (isTarget(a - b) || isTarget(b - a)) return true;
        if (isTarget(a / b) || isTarget(b / a)) return true;
        return false;
    }

    bool isTarget(double a) {
        if (abs(a - 24) < 1e-9) return true;
        return false;
    }
};
