/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(toInt(s));
        }
        NestedInteger curNest;
        stack<NestedInteger> st;
        int tmp = 0;
        bool positive = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                if (i != 0) {
                    st.push(curNest);
                    curNest = NestedInteger();
                }
            } else if (s[i] == ']') {
                if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                    curNest.add(NestedInteger((positive ? tmp : -tmp)));
                    positive = true;
                    tmp = 0;
                }
                if (!st.empty()) {
                    NestedInteger topNest = st.top();
                    st.pop();
                    topNest.add(curNest);
                    curNest = topNest;
                }
            } else if (s[i] == ',') {
                if (s[i - 1] == ']') {
                    continue;
                } else {
                    curNest.add(NestedInteger((positive ? tmp : -tmp)));
                    positive = true;
                    tmp = 0;
                }
            } else if (s[i] == '-') {
                positive = false;
            } else {
                tmp = tmp * 10 + s[i] - '0';
            }
        }
        return curNest;
    }

    int toInt(string s) {
        bool positive = true;
        int pos = 0;
        if (s[0] == '-') {
            positive = false;
            pos = 1;
        }
        int res = 0;
        while (pos < s.length()) {
            res = res * 10 + s[pos] - '0';
            pos++;
        }
        return (positive ? res : -res);
    }
};
