class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> path;
        path.resize(2);
        res.clear();
        int len = S.length();
        long long num1 = 0;
        for (int i = 1; i <= len - 2; i++) {
            if (S[0] == '0' && i != 1) break;
            num1 = num1 * 10 + S[i - 1] - '0';
            if (num1 > 2147483647) break;
            path[0] = num1;
            long long num2 = 0;
            for (int j = i + 1; j <= len - 1; j++) {
                if (S[i] == '0' && j != i + 1) break;
                num2 = num2 * 10 + S[j - 1] - '0';
                if (num2 > 2147483647) break;
                path[1] = num2;
                search(S, j, num1 + num2, path, 2);
            }
        }
        return res;
    }

    void search(string num, int stPos, long long nextNum, vector<int> path, int pathLen) {
        if (res.size() > 0) return;
        if (nextNum > 2147483647) return;
        string next = to_string(nextNum);
        if (next.length() > num.length() - stPos) return;
        if (num.substr(stPos, next.length()) != next) return;
        if (path.size() > pathLen) path[pathLen] = nextNum;
        else path.push_back(nextNum);
        if (next.length() == num.length() - stPos) {
            for (int i = 0; i <= pathLen; i++) res.push_back(path[i]);
            return;
        }
        long long sum = (long long)path[pathLen - 1] + path[pathLen];
        if (sum > 2147483647) return;
        search(num, stPos + next.length(), sum, path, pathLen + 1);
    }

private:
    vector<int> res;
};
