class MyHashMap {
private:
    int size;
    vector<list<pair<int,int>>> table;

public:
    MyHashMap() {
        size = 1000;
        table.resize(size);
    }
    
    void put(int key, int value) {
        int index = key % size;
        
        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second = value;   // update
                return;
            }
        }
        
        table[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = key % size;
        
        for (auto &p : table[index]) {
            if (p.first == key)
                return p.second;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int index = key % size;
        
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */