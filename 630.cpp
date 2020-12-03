class Solution {
public:
    struct Course {
        int duration;
        int endTime;

        bool operator < (const Course& a) const {
            if (duration == a.duration) {
                return endTime < a.endTime;
            }
            return duration < a.duration;
        }
    };

    int scheduleCourse(vector<vector<int>>& courses) {
        int len = courses.size();
        if (len <= 1) return len;

        sort(courses.begin(), courses.end(), cmp);

        int curTime = 0;
        for (int i = 0; i < len; i++) {
            //touch the end time
            Course course;
            course.duration = courses[i][0];
            course.endTime = courses[i][1];

            if (curTime + courses[i][0] > courses[i][1]) {
                if (!qu.empty() && qu.top().duration > courses[i][0]) {
                    curTime -= qu.top().duration;
                    qu.pop();
                    qu.push(course);
                    curTime += courses[i][0];
                } else {
                    continue;
                }
            } else {
                qu.push(course);
                curTime += courses[i][0];
                res++;
            }
        }
        return res;
    }

    static int cmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

private:
    int res = 0;
    priority_queue<Course, vector<Course>, less<Course>> qu;
};