#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>


template<class Data>
class HashTable{
    int num_of_keys;
    int table_size;
    
    static const int INITIAL_SIZE = 10;
    static const int EXPAND_FACTOR = 2;
    static constexpr double SHRINK_FACTOR = 0.5;
    static constexpr double EXPAND_RATIO = 1;
    static constexpr double SHRINK_RATIO = 0.25;
    void expandOrShrink();
    bool checkExpand() const;
    bool checkShrink() const;
public:
    std::vector<std::list<std::pair<int,Data>>> table;
    HashTable() : table(std::vector<std::list<std::pair<int,Data>>>(INITIAL_SIZE)) ,num_of_keys(0), table_size(INITIAL_SIZE){};
    HashTable(int size) : table(std::vector<std::list<std::pair<int,Data>>>(size)), num_of_keys(0), table_size(size){};
    ~HashTable();
    HashTable& operator=(const HashTable& other);
    // list<Array<Lecture*>>*& operator[](unsigned int i);
    bool insert(int key, Data data);
    void erase(int key);
    std::pair<int,Data> Find(int key) const;
    void printKeys() const;
    int getNumOfKeys() const;
    int getTableSize() const;
};

template<class Data>
HashTable<Data>& HashTable<Data>::operator=(const HashTable<Data>& other){
    table = other.table;
    num_of_keys = other.num_of_keys;
    table_size = other.table_size;
    return *this;
}

/**
 * return values:
 * pointer to a paor - when key was found in the DS
 * nullptr - when key was not found in the DS
*/
template<class Data>
std::pair<int,Data> HashTable<Data>::Find(int key) const{

    for(std::pair<int, Data> elem : table[key%table_size]){
        if(key == elem.first){
            return elem;
        }
    }
    std::pair<int, Data> not_found(-1, Data());//res pair when element was not found
    return not_found;
}

/*insert a key when its not in the DS already.
*return values:
*true - succesfull insertion
*false - failed insertion, i.e key already exist
*/
template<class Data>
bool HashTable<Data>::insert(int key, Data data){
    //do nothing if key is already in the list
    std::pair<int,Data> res = Find(key);
    std::pair<int, Data> not_found(-1, Data());
    if(res != not_found){
        return false;
    }
    res.first = key;
    res.second = data;
    table[key%table_size].push_back(res);
    num_of_keys++;
    expandOrShrink();
    return true;
}

/*delete an existing key.
*nothing happens if the key is not in the table
*/
template<class Data>
void HashTable<Data>::erase(int key){
    //nothing to delete
    if(table[key%table_size].size() == 0){
        return;
    }
    //delete key from its list if it's there
    typename std::list<std::pair<int, Data>>::iterator it = table[key%table_size].begin();
    for (; it != table[key%table_size].end(); ++it){
        if((*it).first == key){
            table[key%table_size].erase(it);
            num_of_keys--;
            expandOrShrink();   
            return; 
        }
    }
    return;
}

template<class Data>
HashTable<Data>::~HashTable(){}

template<class Data>
bool HashTable<Data>::checkExpand() const{
    return double(num_of_keys)/table_size >= EXPAND_RATIO;
}

template<class Data>
bool HashTable<Data>::checkShrink() const{
    return double(num_of_keys)/table_size <= SHRINK_RATIO && num_of_keys > INITIAL_SIZE/2;
}

template<class Data>
int HashTable<Data>::getNumOfKeys() const{
    return num_of_keys;
}

template<class Data>
int HashTable<Data>::getTableSize() const{
    return table_size;
}

template<class Data>
void HashTable<Data>::expandOrShrink(){
    int new_size;
    if(checkExpand()){
        new_size = EXPAND_FACTOR * table_size;
    }
    else if(checkShrink()){
        new_size = SHRINK_FACTOR * table_size;
    }
    else{
        return;
    }
    std::vector<std::list<std::pair<int,Data>>> tmp_table(new_size);
    for(int i = 0; i < table_size; ++i){
        for(auto& elem : table[i]){
            std::pair<int,Data> push_pair(elem.first, elem.second);
            tmp_table[(elem.first)%new_size].push_back(push_pair);
        }
    }
    table = tmp_table;
    table_size = new_size;
}

/*print all the keys in the table.
*/
template<class Data>
void HashTable<Data>::printKeys() const{
    for(int i = 0; i < table_size; ++i){
        for(const auto& elem : table[i]){
            std::cout<<elem.first<<" ";
        }
    }
    std::cout<<""<<std::endl;
}

#endif