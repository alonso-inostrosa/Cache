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
};

#endif //CACHE_ITEMS_H