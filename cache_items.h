#ifndef CACHE_ITEMS_H
#define CACHE_ITEMS_H

#include<string>

class CacheItem{
public:
    int priority;
    std::string key;

    CacheItem( int priority, std::string key ){
        this->priority = priority;
        this->key = key;
    }

    friend bool operator<(CacheItem& a, CacheItem& b)  {
        return a.priority > b.priority;
    }

    friend bool operator>(CacheItem& a, CacheItem& b)  {
        return a.priority > b.priority;
    }

    friend bool operator==(CacheItem& a, CacheItem& b)  {
        return a.priority == b.priority;
    }

    friend bool operator!=(CacheItem& a, CacheItem& b)  {
        return a.priority != b.priority;
    }

    friend bool operator<=(CacheItem& a, CacheItem& b)  {
        return a.priority <= b.priority;
    }

    friend bool operator>=(CacheItem& a, CacheItem& b)  {
        return a.priority >= b.priority;
    }
};

#endif //CACHE_ITEMS_H