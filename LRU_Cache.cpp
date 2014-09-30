// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and set.

// get(key) - Get the value (will always be positive) of the key if the key
// exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present.
// When the cache reached its capacity, it should invalidate the least recently
// used item before inserting a new item.

struct cacheEntry {
    int key;
    int value;
    cacheEntry(int k, int v) : key(k), value(v) {}
};

class LRUCache{
    public:
        LRUCache(int capacity) {
            cacheSize = capacity;
        }

        int get(int key) {
            if (cacheMap.find(key) == cacheMap.end())
                return -1;
            cacheEntry cur = *cacheMap[key];
            cacheList.erase(cacheMap[key]);
            cacheList.push_front(cur); // update the most recently used item at the front
            cacheMap[key] = cacheList.begin(); // the cursor in cache table must be updated after cache list
            return cur.value;
        }

        void set(int key, int value) {
            cacheEntry cur(key, value);
            if (cacheMap.find(key) == cacheMap.end()) {
                if (cacheMap.size() == cacheSize) { // cache is full
                    cacheMap.erase((*cacheList.rbegin()).key);
                    cacheList.pop_back();
                }
                cacheList.push_front(cur);
                cacheMap[key] = cacheList.begin();
            } else { // over-write the value of the duplicate key
                cacheList.erase(cacheMap[key]);
                cacheList.push_front(cur);
                cacheMap[key] = cacheList.begin();
            }
        }

    private:
        unordered_map<int, list<cacheEntry>::iterator> cacheMap; // key-cursor pairs
        list<cacheEntry> cacheList; // store the recently set/read at the front
        int cacheSize;
};
