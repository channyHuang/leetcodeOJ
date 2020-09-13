class Solution {
public:
    class Node {
    public:
        int stPos;
        int endPos;
        Node *left;
        Node *right;
        Node(int _stPos = 0, int _endPos = 0) {
            stPos = _stPos;
            endPos = _endPos;
            left = nullptr;
            right = nullptr;
        }
    };

    int findLatestStep(vector<int>& arr, int m) {
        int len = arr.size();
        if (m == len) return len;
        Node *root = new Node(1, len);
        for (int i = len - 1; i >= 0; i--) {
            Node *curNode = root;
            Node *parent = nullptr;
            while (curNode->left || curNode->right) {
                parent = curNode;
                if (curNode->left && curNode->left->endPos >= arr[i]) curNode = curNode->left;
                else curNode = curNode->right;
            }
            if (curNode->endPos - curNode->stPos + 1 < m) continue; 
            //cout << curNode->stPos << " " << curNode->endPos << endl;
            if (curNode->stPos == curNode->endPos) {
                if (parent && parent->left == curNode) {
                    parent->left = nullptr;
                } else if (parent && parent->right == curNode) {
                    parent->right = nullptr;
                }
                delete curNode;
            } else if (curNode->stPos == arr[i]) {
                curNode->stPos++;
                if (curNode->endPos - curNode->stPos + 1 == m) return i;
            } else if (curNode->endPos == arr[i]) {
                curNode->endPos--;
                if (curNode->endPos - curNode->stPos + 1 == m) return i;
            } else {
                if (arr[i] - curNode->stPos == m || curNode->endPos - arr[i] == m) return i; 
                curNode->left = new Node(curNode->stPos, arr[i] - 1);
                curNode->right = new Node(arr[i] + 1, curNode->endPos);               
            }
        }
        return -1;
    }
};
