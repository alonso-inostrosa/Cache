#ifndef CACHE_ITEMS_H
#define CACHE_ITEMS_H

//Para usar hash
#include <functional>

//Para sobrecargar operador << para CacheItem
#include<iostream>

class CacheItem{
public:
    int priority;
    std::string key;

    CacheItem( int priority, std::string key ){
        this->priority = priority;
        this->key = key;
    }

    std::size_t operator()(CacheItem const& ci) const noexcept {
            std::size_t h1 = std::hash<int>{}(ci.priority);
            std::size_t h2 = std::hash<std::string>{}(ci.key);
            return h1 ^ (h2 << 1); 
    }

    friend std::ostream& operator << (std::ostream& os, const CacheItem& ci) {
        os << std::to_string(ci.priority) << "|" << ci.key;
        return os;
    }

    friend bool operator<(CacheItem& a, CacheItem& b)  {
        return a.priority < b.priority;
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

//Para usar Hash sobre objetos CacheItem (inserta la función en el namespace std)
namespace std{
    template<> struct hash<CacheItem>{
        std::size_t operator()(CacheItem const& ci) const noexcept
        {
            std::size_t h1 = std::hash<int>{}(ci.priority);
            std::size_t h2 = std::hash<std::string>{}(ci.key);
            return h1 ^ (h2 << 1); 
        }
    };
}

#endif //CACHE_ITEMS_H