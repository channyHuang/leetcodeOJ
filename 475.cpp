class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int lenHouse = houses.size();
        if (lenHouse <= 0) return 0;
        int lenHeater = heaters.size();
        if (lenHeater <= 0) return 0;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        if (heaters[lenHeater - 1] < houses[0]) return houses[lenHouse - 1] - heaters[lenHeater - 1];
        if (heaters[0] > houses[lenHouse - 1]) return heaters[0] - houses[0];

        int leftDis[lenHouse] = {0};
        int rightDis[lenHouse] = {0};
        int res = 0;

        int posHeater = 0;
        for (int i = 0; i < lenHouse; i++) {
            while (posHeater < lenHeater && houses[i] > heaters[posHeater]) posHeater++;
            if (posHeater >= lenHeater) posHeater = lenHeater - 1;

            rightDis[i] = abs(heaters[posHeater] - houses[i]);

            while (posHeater >= 0 && houses[i] < heaters[posHeater]) posHeater--;
            if (posHeater < 0) posHeater = 0;
            leftDis[i] = abs(heaters[posHeater] - houses[i]);

            if (res < min(leftDis[i], rightDis[i])) res = min(leftDis[i], rightDis[i]);
        }

        return res;
    }
};
