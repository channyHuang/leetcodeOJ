class Solution {
public:
    int hours = 0, mins = 0;

    string largestTimeFromDigits(vector<int>& A) {
        bool used[5] = {0};
        int time[5] = {0};
        char ctime[6] = {0};
        for (int i = 0; i < 4; i++) {
            if (A[i] > 2 || used[i]) continue;
            time[0] = A[i];
            used[i] = true;
            search(time, A, 1, used);
            used[i] = false;
        }
        if (hours == 0 && mins == 0) {
            if (A[0] == 0 && A[1] == 0 && A[2] == 0 && A[3] == 0) return "00:00";
            return "";
        }
        ctime[0] = hours / 10 + '0';
        ctime[1] = hours % 10 + '0';
        ctime[2] = ':';
        ctime[3] = mins / 10 + '0';
        ctime[4] = mins % 10 + '0';
        return string(ctime);
    }

    void search(int time[5], vector<int> A, int pos, bool used[5]) {
        if (pos >= 4) {
            if (time[0] == 2 && time[1] >= 4) return;
            if (time[2] >= 6) return;
            if (hours < time[0] * 10 + time[1]) {
                hours = time[0] * 10 + time[1];
                mins = time[2] * 10 + time[3];
            } else if (hours == time[0] * 10 + time[1] && mins < time[2] * 10 + time[3]) {
                mins = time[2] * 10 + time[3];
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (used[i]) continue;
            time[pos] = A[i];
            used[i] = true;
            search(time, A, pos + 1, used);
            used[i] = false; 
        }
    }
};
