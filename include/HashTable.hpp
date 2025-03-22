//
//  HashTable.hpp
//  PracticeC++
//
//  Created by Scott Novak on 7/15/22.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// let's first create a hash item and a has table

// want to create the hash map with T key type and U value type
// with int as size
template <typename T, typename U> class HashMap {

  private:
    typedef struct {
        T key;
        U value;

    } HashMapItem;

    typedef struct {
        HashMapItem** hashMapItems;
        int totalSize;
        int numOfItems;

    } HashMapTable;

    HashMapTable myHashMapTable;

    unsigned int calculateHash(T key) {
        unsigned int hash = (((key * 10) / 3) * 17) - 4;
        hash %= myHashMapTable.totalSize;
        return hash;
    }

  public:
    HashMap(int size) {
        myHashMapTable.totalSize = size;
        myHashMapTable.numOfItems = 0;
        myHashMapTable.hashMapItems = (HashMapItem**)calloc(size, sizeof(HashMapItem));
        for (int i = 0; i < size; i++) {
            myHashMapTable.hashMapItems[i] = nullptr;
        }
    }

    void insertItem(T key, U value) {
        unsigned int index = calculateHash(key);
        if (myHashMapTable.hashMapItems[index] == nullptr) {

            HashMapItem* ptr = (HashMapItem*)malloc(sizeof(HashMapItem));
            ptr->key = key;
            ptr->value = value;
            myHashMapTable.hashMapItems[index] = ptr;

            myHashMapTable.hashMapItems[index]->key = key;
            myHashMapTable.hashMapItems[index]->value = value;
        }
    }

    void insertItem(T key, std::string value) {
        unsigned int index = calculateHash(key);
        if (myHashMapTable.hashMapItems[index] == nullptr) {

            HashMapItem* ptr = (HashMapItem*)malloc(sizeof(HashMapItem));
            ptr->key = key;
            ptr->value = value;
            myHashMapTable.hashMapItems[index] = ptr;

            myHashMapTable.hashMapItems[index]->key = key;
            myHashMapTable.hashMapItems[index]->value = value;
        }
    }

    void removeItem(T key) {
        unsigned int index = calculateHash(key);
        HashMapItem* item = myHashMapTable.hashMapItems[index];
        std::free(item);
        myHashMapTable.hashMapItems[index] = nullptr;
    }

    void displayItem(T key) {
        unsigned int index = calculateHash(key);
        HashMapItem* item = (myHashMapTable.hashMapItems[index]);
        if (item != nullptr) {
            std::cout << item->value << std::endl;
        } else {
            std::cout << "Key: " << key << " does not exist." << std::endl;
        }
    }

    void cleanUp() {
        for (int i = 0; i < myHashMapTable.totalSize; i++) {
            if (myHashMapTable.hashMapItems[i] != nullptr) {
                std::free(myHashMapTable.hashMapItems[i]);
                myHashMapTable.hashMapItems[i] = nullptr;
            }
        }

        if (myHashMapTable.hashMapItems != nullptr) {
            std::free(myHashMapTable.hashMapItems);
            myHashMapTable.hashMapItems = nullptr;
        }
    }
};

// template<>  void HashMap<std::string>::insertItem(T key, std::string value);

#endif /* HashTable_hpp */
