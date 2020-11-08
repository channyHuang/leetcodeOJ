class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        hlen = heights.size();
        heaplen = 0;
        int stPos = 0;
        while (stPos < hlen - 1) {
            if (heights[stPos + 1] <= heights[stPos]) {
                stPos++;
                continue;
            }
            int need = heights[stPos + 1] - heights[stPos];
            if (heaplen < ladders) {
                heap.push_back(need);
                heaplen++;
                upHeap();
            } else if (ladders == 0) { 
                if (bricks < need) break;
                bricks -= need;
            } else {
                if (heap[0] < need) {
                    if (bricks < heap[0]) break;
                    bricks -= heap[0];
                    heap[0] = need;
                    downHeap();
                } else {
                    if (bricks < need) break;
                    bricks -= need;
                }
            }
            stPos++;
        }
        return stPos;
    }

    void upHeap() {
        int idx = heaplen - 1;       
        while (idx > 0) {
            int nextIdx = (idx - 1) / 2;
            if (heap[nextIdx] > heap[idx]) {
                int tmp = heap[nextIdx];
                heap[nextIdx] = heap[idx];
                heap[idx] = tmp;
                idx = nextIdx;
            } else break;
        }
    }

    void downHeap() {
        int idx = 0;
        int nextIdx = idx * 2 + 1;
        while (nextIdx < heaplen) {        
            int nnext = nextIdx + 1;
            if (nnext < heaplen && heap[nnext] < heap[nextIdx]) {
                nextIdx = nnext;
            }
            if (heap[idx] > heap[nextIdx]) {
                int tmp = heap[idx];
                heap[idx] = heap[nextIdx];
                heap[nextIdx] = tmp;
                idx = nextIdx;
                nextIdx = idx * 2 + 1;
            } else break;
        }
    }

private:
    int hlen;
    vector<int> heap;
    int heaplen;
};
