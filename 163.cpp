class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for (int i = 0; i < numbers.size() - 1; i++) {
            int j = find(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            if (j != -1) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
        }
        return res;
    }

    int find(vector<int>& numbers, int stPos, int endPos, int target) {
        if (stPos > endPos) return -1;
        if (numbers[stPos] > target || numbers[endPos] < target) return -1;

        int midPos = (stPos + endPos) / 2;
        if (numbers[midPos] == target) return midPos;
        else if (numbers[midPos] > target) return find(numbers, stPos, midPos - 1, target);
        else return find(numbers, midPos + 1, endPos, target);
    }
};

/*
 * 好像时间和空间都有待提高哦。。。可是为什么呢？
 */
