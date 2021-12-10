#ifndef CACHE_H
#define CACHE_H

#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <memory>

#include "cache_items.h"

class Cache {
private:
    //Comparador, para la cola de prioridad
    class LessThanComparator : public std::binary_function< std::shared_ptr<CacheItem>, std::shared_ptr<CacheItem>,bool>{
    public:
      bool operator()(std::shared_ptr<CacheItem> ci1, std::shared_ptr<CacheItem> ci2) const {
        return ci1 < ci2;
      }
  };

    //Cola de Prioridad, para determinar (en base a politica LFR o LFU) elementos a desalojar
    std::priority_queue<std::shared_ptr<CacheItem>, std::vector<std::shared_ptr<CacheItem>>> pq;

    //Mapa para almacenar los elementos de la Cache (para hit/miss)
    std::map<size_t, std::shared_ptr<CacheItem> > contents;

public:

    void insert( std::shared_ptr<CacheItem> ci ){
        pq.push( ci );

        std::hash<CacheItem> hs;
        size_t key = hs( *ci );
        std::cout << "Inserting key=" << key << " elem=" << *ci << std::endl;
        contents[ key ] = ci;
    }

    void remove(){
    
    }

    void print_map(){
        for( const auto &elem : contents){
            std::cout << "[" << elem.first << "]=" << *(elem.second) << std::endl;
        }
    }

    void print_queue() {
        //std::priority_queue<std::shared_ptr<CacheItem>, std::vector<std::shared_ptr<CacheItem>>> pq_temp = pq;

        while( !pq.empty() ){
            std::shared_ptr<CacheItem> ci = pq.top( );
            std::cout << *ci << std::endl;
            pq.pop( );
        }
    }

};
#endif