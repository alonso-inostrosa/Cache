#include "cache.h"
#include "cache_items.h"

#include <iostream>
#include <string>
#include <iomanip>


//Para usar hash
#include <functional>

int main(int argc, char* argv[] ){

    std::shared_ptr<CacheItem> c_item_3b = std::make_shared<CacheItem>( 3, "tres" );
    std::shared_ptr<CacheItem> c_item_3c = std::make_shared<CacheItem>( 3, "tres" );    
    std::shared_ptr<CacheItem> c_item_1 = std::make_shared<CacheItem>( 6, "seis" );
    std::shared_ptr<CacheItem> c_item_2 = std::make_shared<CacheItem>( 7, "siete" );
    std::shared_ptr<CacheItem> c_item_3a = std::make_shared<CacheItem>( 3, "tres" );

    Cache cache;
    cache.insert( c_item_3c );
    cache.insert( c_item_1 );
    cache.insert( c_item_2 );
    cache.insert( c_item_3a );
    cache.insert( c_item_3b );
    
    cache.print_map();

    //Al recorrer muestra 3, 7 y luego 6??? Revisar
    cache.print_queue();

    return EXIT_SUCCESS;
}