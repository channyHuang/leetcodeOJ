class Solution {
public:
    int dayOfYear(string date) {
        int res = 0;
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = 0, month = 0, day = 0;
        for (int i = 0; i < 4; i++) {
            year = year * 10 + date[i] - '0';
        }
        month = 10 *(date[5] - '0') + date[6] - '0';
        month--;
        day = 10 *(date[8] - '0') + date[9] - '0';
        bool run = false;
        if (year % 100 == 0) {
            run = (year % 400 == 0 ? true : false);
        } else run = (year % 4 == 0 ? true : false);
        if (run) days[1]++;
         for (int i = 0; i < month; i++) res += days[i];
         res += day; 
         return res;
    }
};
