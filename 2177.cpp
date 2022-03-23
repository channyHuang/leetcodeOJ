class Solution {
public:
    vector<long long> sumOfThree(long long num) {
      vector<long long> res;
      if (num % 3 != 0) return res;
      res.resize(3, 0);
      res[1] = num / 3;
      res[0] = res[1] - 1;
      res[2] = res[1] + 1;
      return res;
    }
};
