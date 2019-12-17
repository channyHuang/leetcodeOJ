class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> w= {"Sunday", "Monday", "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};    
        tm now{.tm_mday = day,
                .tm_mon = month - 1,
                .tm_year = year - 1900};
        mktime(&now);
        return w[now.tm_wday];
    }
};
