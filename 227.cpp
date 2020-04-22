class Solution {
public:
    int calculate(string s) {
        stack<long long> numbers;
        stack<char> operaters;
        long long res;
        int len = s.length();
        long long num = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') continue;
            if (s[i] > '9' || s[i] < '0') {
                if (operaters.empty()) {
                    operaters.push(s[i]);
                    numbers.push(num);
                }
                else if (operaters.top() == '*') {
                    long long num1 = numbers.top();
                    numbers.pop();
                    numbers.push(num1 * num);
                    operaters.pop();
                    operaters.push(s[i]);
                } else if (operaters.top() == '/') {
                    long long num1 = numbers.top();
                    numbers.pop();
                    numbers.push(num1 / num);
                    operaters.pop();
                    operaters.push(s[i]);
                } else {
                    operaters.push(s[i]);
                    numbers.push(num);
                }
                num = 0;
            } else {
                num = num * 10 + s[i] - '0';
            }
        }
        if (operaters.empty()) return num;

        if (operaters.top() == '*') {
            res = numbers.top();
            numbers.pop();
            res *= num;
            operaters.pop();
        } else if (operaters.top() == '/') {
            res = numbers.top();
            numbers.pop();
            res /= num; 
            operaters.pop();
        } else res = num;

        while (!numbers.empty()) {
            char ope = operaters.top();
            operaters.pop();
            num = numbers.top();
            numbers.pop();
            if (ope == '+') {
                if (operaters.empty() || operaters.top() == '+') {                   
                    res += num;
                } else res = num - res;
            } else {
                if (operaters.empty() || operaters.top() == '+') {
                    res = num - res;
                } else res += num;
            }
        }

        return res;
    }
};
