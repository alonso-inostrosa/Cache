#ifndef CACHE_H
#define CACHE_H

#include <queue>
#include <vector>
#include <string>
#include<iostream>
#include<map>
#include<algorithm>
#include<memory>

#include<cache_items.h>

class Cache {
private:
    //Comparador, para la cola de prioridad
    class LessThanComparator : public std::binary_function<std::shared_ptr<CacheItem>,std::shared_ptr<CacheItem>,bool>{
    public:
      bool operator()(std::shared_ptr<CacheItem> ci1, std::shared_ptr<CacheItem> ci2) const {
        return ci1->priority > ci2->priority;
      }
  };

    //Cola de Prioridad, para determinar (en base a politica LFR o LFU) elementos a desalojar
    std::priority_queue<std::shared_ptr<CacheItem>, std::vector<std::shared_ptr<CacheItem>>, LessThanComparator> pq;

    //Mapa para almacenar los elementos de la Cache (para hit/miss)
    std::map<std::string, std::shared_ptr<CacheItem> > contents;

public:

    void insert( ){

    }

    void remove(){
    
    }

    template<typename T> void print_queue(T q) {

    }

};
#endif