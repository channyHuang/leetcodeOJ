class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        nums = A;
        pos = 0;
    }
    
    int next(int n) {
        int pos = 0; 
        while (1) {
            if (n <= nums[pos]) {
                nums[pos] -= n;
                return nums[pos + 1];
            }
            n -= nums[pos];
            nums[pos] = 0;
            pos += 2;
            if (pos >= nums.size()) return -1;
        }
        return -1;
    }

private:
    vector<int> nums;
    int pos;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
