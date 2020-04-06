class Solution {
public:
    class Node {
    public:
        int height;
        int count;
        Node *pre;
        Node *next;
        Node(int _h = 0, int _c = 0) {
            height = _h;
            count = _c;
            pre = nullptr;
            next = nullptr;
        }
    };

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        int len = people.size();
        if (len <= 0) return res;
        sort(people.begin(), people.end(), cmp);
        Node *head = new Node(people[0][0], people[0][1]);
        Node *tail = head;
        int i = 1;
        while (i < len && people[i][1] == 0) {
            Node *node = new Node(people[i][0], people[i][1]);
            tail->next = node;
            tail = node;
            i++;
        }
        for (; i < len; i++) {
            Node *node = head;
            int cnt = people[i][1];
            Node *newNode = new Node(people[i][0], people[i][1]);
            while (1) {
                if (node->height >= people[i][0]) cnt--;
                if (cnt == 0 && (node->next == nullptr || node->next->height >= people[i][0])) {
                    newNode->next = node->next;
                    newNode->pre = node;
                    if (node->next != nullptr) node->next->pre = newNode;
                    node->next = newNode;
                    if (node == tail) tail = tail->next;
                    break;
                }
                if (node->next != nullptr) node = node->next;
                else break;
            }
            
        }

        Node *node = head;
        while (node) {
            vector<int> sub;
            sub.push_back(node->height);
            sub.push_back(node->count);
            res.push_back(sub);
            node = node->next;
        }
        return res;
    }
};
