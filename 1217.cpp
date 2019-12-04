class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
         int len = chips.size();
		 if (len <= 1) return 0;
		 int countEven = 0;
		 for (int i = 0; i < len; i++) {
			if (chips[i] % 2 == 0) countEven++;
		 }
		 return min(countEven, len - countEven);
    }
};
