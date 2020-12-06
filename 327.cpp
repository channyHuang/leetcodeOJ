class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        sets.insert(0);
        long long sum = 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            multiset<long long>::iterator itr1 = sets.lower_bound(sum - upper);
            multiset<long long>::iterator itr2 = sets.upper_bound(sum - lower);
            res += distance(itr1, itr2);
            sets.insert(sum);
        }
        return res;
    }

private:
    multiset<long long> sets;
};
