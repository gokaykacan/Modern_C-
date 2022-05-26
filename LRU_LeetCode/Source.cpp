#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
#include <iostream>

using namespace std;

class LRUCache {
    int CAPACITY;
    list<pair<int, int>> myList;
    unordered_map<int, int> myCache;
public:
    LRUCache(int capacity) : CAPACITY(capacity) {}

    int get(int key)
    {
        for (list<pair<int, int>>::iterator it = myList.begin(); it != myList.end(); it++)
        {
            if (it->first == key )
            {
                updateMyList(key, myCache[key]);
                return myCache[key];
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (myCache.size() < CAPACITY)
        {
            myCache[key] = value;
            myList.push_front(pair<int, int>(key, value));
        }
        else
        {
            int tempValue = myList.back().second;
            myList.pop_back();
            myList.push_front(pair<int, int>(key, value));
            myCache.erase(tempValue);
            myCache[key] = value;

        }

    }
    void updateMyList(int key, int value)
    {
        for (list<pair<int, int>>::iterator it = myList.begin(); it != myList.end(); it++)
        {
            if (it->second == value)
            {
                myList.erase(it);
                myList.push_front(pair<int, int>(key, value));
                return;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    cout << "Hello World\n";

    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // return 1

    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2) << endl;;    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1) << endl;;    // return -1 (not found)
    cout << lRUCache->get(3) << endl;;    // return 3
    cout << lRUCache->get(4) << endl;;    // return 4

    delete lRUCache;
    return 0;
}
