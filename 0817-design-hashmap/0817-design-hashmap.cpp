class MyHashMap {
public:

    vector<pair<int, int>> map;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(auto &i:map){
            if(i.first == key){
                i.second = value;
                return;
            }
        }
        map.push_back({key, value});
    }
    
    int get(int key) {
        for(auto i:map){
            int k = i.first;
            int val = i.second;
            if(k == key) return val;
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto i = map.begin(); i < map.end(); i++){
            if(i->first == key){
                map.erase(i);
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