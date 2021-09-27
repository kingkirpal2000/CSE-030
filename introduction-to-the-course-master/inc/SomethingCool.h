#ifndef MS_h
#define MS_h

#include <iostream>

struct Node {
    long data;
    Node* next;
    
    Node(){
        
    }
    
    Node(long data){
        this->data = data;
        next = NULL;
    }
};

struct MyStruct {
    
    Node** array;
    long size;
    
    MyStruct(long size=10000){
    
        array = (Node**)malloc(sizeof(Node*) * size);
        
        for (int i = 0; i < size; i++){
            array[i] = NULL;
        }
        this->size = size;
    }
    
    long coolOperation(long value){
        long result =  value % size;
        if (result < 0){
            result *= -1;
        }
        
        return result;
    }
    
    void insert(long value){
        long index = coolOperation(value);
        
        Node* newNode = new Node(value);
        Node* oldHead = array[index];
        
        array[index] = newNode;
        array[index]->next = oldHead;
    }
    
    bool search(long value){
        long index = coolOperation(value);
        
        
        Node* curr = array[index];
        while (curr != NULL){
            if (curr->data == value){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    
    void print(){
        for (long i = 0; i < size; i++){
            Node* curr = array[i];
            if (curr != NULL){
                while (curr != NULL){
                    std::cout << curr->data << " ";
                    curr = curr->next;
                }
                std::cout << std::endl;
            }
        }
    }
    
    ~MyStruct(){
        free(array);
    }
};


#endif 

