class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int len = aliceValues.size();
        vector<pair<int, int>> sumValues(len);
        for (int i = 0; i < len; i++) {
            sumValues[i] = pair<int, int>(aliceValues[i] + bobValues[i], i);
        }
        sort(sumValues.begin(), sumValues.end(), greater());
        int aValue = 0, bValue = 0;
        for (int i = 0; i < len; i++) {
            if (i & 1) bValue += bobValues[sumValues[i].second];
            else aValue += aliceValues[sumValues[i].second];
        }
        return (aValue > bValue ? 1 : (aValue == bValue ? 0 : -1));
    }
};
