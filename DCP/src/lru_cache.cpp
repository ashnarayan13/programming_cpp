//
// Created by asmu270293 on 25.01.2019.
//

#include <iostream>
#include <list>
#include <unordered_map>

class LRU{
    std::list<int> keys;
    std::unordered_map<int, std::list<int>::iterator >cache_list;
    int cache_size;

public:
    LRU(int n){
        cache_size = n;
    }
    void refer(int x){
        if(cache_list.find(x) == cache_list.end()){
            if(keys.size() == cache_size){
                int last = keys.back();
                keys.pop_back();
                cache_list.erase(last);
            }
        }
        else{
            keys.erase(cache_list[x]);
        }
        keys.push_front(x);
        cache_list[x] = keys.begin();
    }
    void display(){
        for(std::list<int>::iterator it = keys.begin(); it!=keys.end(); it++){
            std::cout<<*it<<" ";
        }
        std::cout<<std::endl;
    }
};

int main(){
    LRU cache(4);
    cache.refer(1);
    cache.refer(2);
    cache.refer(3);
    cache.refer(1);
    cache.refer(4);
    cache.refer(5);
    cache.display();

    return 0;
}