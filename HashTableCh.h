//
//  HashTableCh.h
//  Hashing
//
//  Created by Eugene Sumaryev on 4/28/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef HashTableCh_h
#define HashTableCh_h

#include "HashNode.h"
#include <cstdlib>  //
#include <set>      //
#include <string>
#include <iostream>

namespace ClassProgram
{
    
    //A struct to hold a list of graph nodes
    struct NodeList
    {
        struct HashNode* head;
        struct HashNode* tail;
        NodeList(){
            head = NULL;
            tail = NULL;
        }
    };

    class HashTableCh
    {
    public:
        
        // TYPEDEF
        typedef string RecordType;
        typedef double valueType;
        // MEMBER CONSTANT
        static const std::size_t SIZE = 27;
        
        
        // CONSTRUCTOR
        HashTableCh();
        
        // MODIFICATION MEMBER FUNCTIONS
        void insert(RecordType& entry, valueType& value);
        void remove(string key);
        
        // CONSTANT MEMBER FUNCTIONS
        //bool isPresent(int key) const;
        HashNode* find(string key); //const
        std::size_t size() const { return total; }
        void printList();
        
    private:

        // MEMBER VARIABLES
        NodeList *dataArray;
        std::size_t total;
        
        // HELPER FUNCTIONS
        std::size_t hash(string key); //const
        
        int useIndex;
    };
}



#endif /* HashTableCh_h */
