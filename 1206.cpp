class Skiplist {
public:
    class Node {
    public:
        int minn;
        int maxn;
        Node* left;
        Node* right;
        int count;
        Node(int _minn = 0, int _maxn = 0) {
            minn = _minn;
            maxn = _maxn;
            left = nullptr;
            right = nullptr;
            count = 0;
        }
    };

    Skiplist() {
        root = new Node(0, 20000);
    }
    
    bool search(int target) {
        Node* cur = root;
        while (cur != nullptr) {
            if (cur->minn == cur->maxn && cur->minn == target) return true;
           
            int mid = (cur->minn + cur->maxn) / 2;
            if (target <= mid) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return false;
    }
    
    void add(int num) {
        Node* cur = root;
        while (cur != nullptr) {
            if (cur->minn == cur->maxn && cur->minn == num) {
                cur->count++;
                return;
            }
            int mid = (cur->minn + cur->maxn) / 2;
            if (num <= mid) {
                if (cur->left == nullptr) {
                    cur->left = new Node(cur->minn, mid);
                }
                cur = cur->left;
            } else {
                if (cur->right == nullptr) {
                    cur->right = new Node(mid + 1, cur->maxn);
                }
                cur = cur->right;
            }
        }
    }
    
    bool erase(int num) {
        Node* cur = root;
        Node* pre = cur;
        bool bleft = false;
        while (cur != nullptr) {
            if (cur->minn == cur->maxn && cur->minn == num) {
                cur->count--;
                if (cur->count == 0) {
                    delete cur;
                    if (bleft) {
                        pre->left = nullptr;
                    } else {
                        pre->right = nullptr;
                    }
                }
                return true;
            }
            int mid = (cur->minn + cur->maxn) / 2;
            pre = cur;
            if (num <= mid) {
                cur = cur->left;
                bleft = true;
            } else {
                cur = cur->right;
                bleft = false;
            }

        }
        return false;
    }

private:
    Node *root;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
