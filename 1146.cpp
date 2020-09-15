class SnapshotArray {
public:
    SnapshotArray(int length) {
        len = length;
        snapId = 0;
        vec.push_back(unordered_map<int, int>());
    }
    
    void set(int index, int val) {
        vec[snapId][index] = val;
    }
    
    int snap() {
        snapId++;
        vec.push_back(vec[snapId - 1]);
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        unordered_map<int, int>::iterator itr = vec[snap_id].find(index);
        if (itr == vec[snap_id].end()) return 0;
        return itr->second;
    }
private:
    vector<unordered_map<int, int>> vec;
    int len;
    int snapId;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
