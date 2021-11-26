#include "cache.h"
#include "cache_items.h"

#include <iostream>

int main(int argc, char* argv[] ){

    std::shared_ptr<CacheItem> c_item_1 = std::make_shared<CacheItem>( 6, "seis" );
    std::shared_ptr<CacheItem> c_item_2 = std::make_shared<CacheItem>( 7, "siete" );
    std::shared_ptr<CacheItem> c_item_3 = std::make_shared<CacheItem>( 3, "tres" );

    Cache cache;
    cache.insert( c_item_1 );
    cache.insert( c_item_2 );
    cache.insert( c_item_3 );

    cache.print_queue();

    return EXIT_SUCCESS;
}