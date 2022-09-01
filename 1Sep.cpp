// Question - https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    list<int> lru;
    unordered_map<int,pair<int,list<int>::iterator> > m;
    int capacity;
    int size;
    
    LRUCache(int capacity = 1000) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        
        lru.erase(m[key].second);
        lru.push_back(key);
        m[key].second = prev(lru.end());
        
        return m[key].first;
    }
    
    void put(int key, int  value) {
        if (m.find(key) != m.end()){
            lru.erase(m[key].second);
            m.erase(key);
            size--;
        }
        lru.push_back(key);
        m[key] = {value,prev(lru.end())};
        size++;
        if (size > capacity){
            m.erase(lru.front());
            lru.pop_front();
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
