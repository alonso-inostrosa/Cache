#include "cache.h"
#include "cache_items.h"

#include <iostream>
#include <string>
#include <iomanip>

//Para usar Hash sobre objetos CacheItem (inserta la función en espacio std)
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

//Para usar hash
#include <functional>

int main(int argc, char* argv[] ){

    
    std::shared_ptr<CacheItem> c_item_1 = std::make_shared<CacheItem>( 6, "seis" );
    std::shared_ptr<CacheItem> c_item_2 = std::make_shared<CacheItem>( 7, "siete" );
    std::shared_ptr<CacheItem> c_item_3a = std::make_shared<CacheItem>( 3, "tres" );
    std::shared_ptr<CacheItem> c_item_3b = std::make_shared<CacheItem>( 3, "tres" );
    std::shared_ptr<CacheItem> c_item_3c = std::make_shared<CacheItem>( 3, "tres" );

    std::hash<CacheItem> hs;

    std::cout << "hash(" << *c_item_1 << ")=" << hs( *c_item_1 ) << std::endl;

    Cache cache;
    cache.insert( c_item_3c );
    cache.insert( c_item_1 );
    cache.insert( c_item_2 );
    cache.insert( c_item_3a );
    cache.insert( c_item_3b );
    

    std::cout << "Equals? " << (c_item_3a == c_item_3b) << std::endl;

    cache.print_queue();

    return EXIT_SUCCESS;
}