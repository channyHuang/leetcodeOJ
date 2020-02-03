class Solution {
public:
    class Node {
    public:
        int value;
        int idx;
        Node *next;

        Node (int _value = 0, int _idx = 0) {
            value = _value;
            idx = _idx;
            next = NULL;
        }
    };

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;
        int len = arr.size();
        if (len <= 0) return arr;
        set<int> sortarr;
        int count = 1;
#define maxn  1007
        Node *nodes[maxn];

        for (int i = 0; i < len; i++) {
            sortarr.insert(arr[i]);
        }
        for (int i = 0; i < maxn; i++) {
            nodes[i] = NULL;
        }
        
        for (set<int>::iterator itr = sortarr.begin(); itr != sortarr.end(); itr++) {
            int idx = (*itr) % maxn;
            while (idx < 0) idx = ((idx + maxn) % maxn);
            Node *curNode = nodes[idx];
            if (curNode == NULL) nodes[idx] = new Node(*itr, count);
            else {             
                while (curNode->next != NULL) {
                    if (curNode->value == *itr) {
                        break;
                    }
                    curNode = curNode->next;    
                }
                if (curNode->value == *itr) {
                    continue;
                }
                curNode->next = new Node(*itr, count);
            }
            count++;
        }
        for (int i = 0; i < len; i++) {
            int idx = (arr[i] % maxn);
            while (idx < 0) idx = ((idx + maxn) % maxn);
            Node *curNode = nodes[idx];
            while (curNode != NULL && curNode->value != arr[i]) curNode = curNode->next;
            if (curNode == NULL) res.push_back(0);
            else res.push_back(curNode->idx);
        }

        return res;
    }
};