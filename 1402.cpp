class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int len = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int sum = 0;
        int i;
        for (i = 0; i < len; i++) {
            if (sum + satisfaction[i] >= 0) {
                sum += satisfaction[i];
            } else break;
        }
        sum = 0;
        int time = 1;
        for (int j = i - 1; j >= 0; j--) {
            sum += (satisfaction[j] * time);
            time++;
        }
        return sum;
    }
};
