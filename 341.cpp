/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {    
        topNest = nestedList;
        pos = 0;
    }
    
    int next() {
        pos++;
        return topNest[pos - 1].getInteger();
    }
    
    bool hasNext() {        
        while (1) {
            while (pos >= topNest.size()) {
                if (st.empty()) return false;
                topNest = st.top();
                st.pop();
                pos = stPos.top();
                stPos.pop();
                pos++;
            }

            if (topNest[pos].isInteger()) return true;

            vector<NestedInteger> tmpNest = topNest;
            st.push(tmpNest);
            int tmp = pos;
            stPos.push(tmp);
            topNest = tmpNest[pos].getList();
            pos = 0;      
        }
        return false;
    }

private:
    stack<vector<NestedInteger>> st;
    stack<int> stPos;

    vector<NestedInteger> topNest;
    int pos;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
