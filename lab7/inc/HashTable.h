#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include <ostream>
#include <string>
#include <LinkedList.h>

using namespace std;

int K = 100000;

struct HashTable {
    LinkedList* table;

    HashTable(){
        table = new LinkedList[100000];
    }

    int f(string word){
        int seed = 131;
        unsigned long hash = 0;
        for(int i = 0; i < word.length(); i++)
        {
            hash = (hash * seed) + word[i];
        }
        return hash % K;
    }
    // int f(string word){
    //     int asciiNums = 0;

    //     if(word.size() > 3){
    //         for(int i = 0; i < 4; i++){
    //             asciiNums += (int)(word[i]);
    //         }
    //     } else {
    //         for(int i = 0; i < word.size(); i++){
    //             asciiNums += (int)(word[i]);
    //         }
    //     }

    //     return asciiNums % K; //tells you the index
    // }
    void insert(string word){
        table[f(word)].append(word);
    }

    bool search(string word){
        int index = f(word);
        return table[index].search(word);
    }

    void print(){
        for(int i = 0; i < K; i++){
            cout << i << ": " << table[i] << endl;
        }
    }

};


#endif