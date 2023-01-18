class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find_first_of("=", 0);
        bool hasx = false;
        vector<int> left = phase(equation, 0, pos - 1, hasx);
        vector<int> right = phase(equation, pos + 1, equation.length() - 1, hasx);
        //cout << "left " << left[0] << " " << left[1] << endl;
        //cout << "right " << right[0] << " " << right[1] << endl;
        left[0] -= right[0];
        right[1] -= left[1];
        if (!hasx) {
            return "No solution";
        }
        if (left[0] == 0) {
            return (right[1] == 0 ? "Infinite solutions" : "No solution");
        }
        return "x=" + to_string(right[1] / left[0]);
    }

    vector<int> phase(string equation, int stpos, int endpos, bool &hasx) {
        vector<int> res(2, 0);
        bool positive = true;
        int value = 0;
        bool isx = false;
        for (int i = stpos; i <= endpos; ++i) {
            if (equation[i] == '+' || equation[i] == '-') {
                if (isx) {
                    res[0] += (positive ? value : -value);
                }
                else res[1] += (positive ? value : -value);
                isx = false;
                positive = (equation[i] == '+' ? true : false);
                value = 0;
            } else if (equation[i] == 'x') {
                if (value == 0) {
                    if (i == 0 || equation[i - 1] < '0' || equation[i - 1] > '9') value = 1;
                }
                isx = true;
                hasx = true;
            } else {
                value = value * 10 + equation[i] - '0';
            }
        }
        if (isx) {
            res[0] += (positive ? value : -value);
        }
        else res[1] += (positive ? value : -value);
        return res;
    }
};
