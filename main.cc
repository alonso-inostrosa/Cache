#include "cache.h"
#include "cache_items.h"

#include <iostream>

int main(int argc, char* argv[] ){

    CacheItem* c_item_1 = new CacheItem(6);
    CacheItem* c_item_2 = new CacheItem(7);
    CacheItem* c_item_3 = new CacheItem(3);

    Cache cache;
    cache.insert();

    return EXIT_SUCCESS;
}