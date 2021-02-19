class SnapshotArray {
private:
    map<int, map<int,int> > arr; //(index, snapid, value)
    int snapId;
    
public:
    SnapshotArray(int length) {
        snapId = 0;
        for(int i=0; i<length; i++) arr[i][snapId] = 0;
    }
    
    void set(int index, int val) {
        arr[index][snapId] = val;
    }
    
    int snap() {
        snapId++;
        return (snapId-1);
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id); //right after snap_id
        if(it == arr[index].begin()) return 0;
        
        --it; //now it's snap id is <= the snap_id we want
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */