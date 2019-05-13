//
//  HashTableCh.cpp
//  Hashing
//
//  Created by Eugene Sumaryev on 4/28/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//



#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>  
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>     // Provides isdigit
#include <cstdlib>
#include <sstream>
#include <cstring>
#include "HashTableCh.h"


namespace ClassProgram
{
    
    HashTableCh::HashTableCh()
    {
        dataArray = new NodeList[SIZE];
        total = 0;
    }
    
    void HashTableCh::insert(RecordType& entry, valueType& value)
    //
    {
        std::size_t index;        // data[index] is location for the new entry
    //    HashNode* testNode;
        
        index = hash(entry);
       /*
        cout << "\n Insert called: \n";
        cout << "hash index is: "<< index << " ";
        cout << "Inserting name : "<< entry << " ";
        cout << "Inserting value: "<< value << endl;
        */
        
        
        //extract the head node
       // RecordType newValue = dataArray[index].head->getNameData();
        //create new node
        //HashNode *newNode = new HashNode(newValue);
        
        HashNode *newNode = new HashNode(entry, value);
      
        
        //set the head and the tail of the list
        //for the first node
        if(dataArray[index].head == NULL) {
            dataArray[index].head = newNode;
            dataArray[index].tail = dataArray[index].head;
        }
        else {
       
        //set tail's link to new node
       // dataArray[index].tail->setLink(newNode);
        
        //set new nodes link to the tail
        newNode->setLink(dataArray[index].tail);

        
       // dataArray[index].tail->setLink(newNode);
        
        //make it the new tail
        dataArray[index].tail = newNode;
        
            /*
        testNode = dataArray[index].tail;
        cout << "TESTING: " << testNode->getNameData() << " - " << testNode->getValueData() << ", ";
        
        testNode = testNode->getLink();
       
        if (testNode !=NULL)
            cout << "TESTING 2: " << testNode->getNameData() << " - " << testNode->getValueData() << ", ";
        */
        
        ++total;
        }
       
        /*
        if (find(entry).empty())
        {
            
            
            //extract the head node
            RecordType newValue = dataArray[index].head->getNameData();
            //create new node
            HashNode *newNode = new HashNode(newValue);
            
            //set tail's link to new node
            //dataArray[index].tail->setLink(newNode);
           
            //set new nodes link to the tail
            newNode->setLink(dataArray[index].tail->getLink());
            
            //make it the new tail
            dataArray[index].tail = newNode;
            ++total;
            
        }
        // If the key wasn't already there, then find the location for the new entry.
        else
            index = find(entry); //otherwise replace the old entry
         */
        
       // data[index] = entry;
        
        
    }
    
    
    
    void HashTableCh::remove(string key){
        
        std::size_t index;
        HashNode *tempNode;
        
        if (find(key) != NULL)
        {
            
            //move the tail to the next value, removing the last value
            //dataArray[index].tail = dataArray[index].tail->getLink();
            //this would be the variable of the last scope, tail will always
            //point to node that was declared last
            
            index = hash(key);
            tempNode = dataArray[index].tail;
            
            //dataArray[index].tail->setLink(dataArray[index].tail->getLink());
           
            dataArray[index].tail = dataArray[index].tail->getLink();
            --total;
            
            delete tempNode;
        }
    }
    
    //function that returns the index of the element if it's present
    //or -1 otherwise
    HashNode* HashTableCh::find(string key) 
    //
    {
        HashNode* found;
       // HashNode* cursor;
        bool done = false;
        std::size_t index;
        
        index = hash(key);
      //  cout << "\n Find was called: \n";
      //  cout << "hash index is: "<< index << " ";
      //  cout << "key to search is: "<< key << endl;
        
        
        if(dataArray[index].head != NULL) {
            
            found = dataArray[index].tail;
            //search the list and get the node that matches
            //get the data from the tail of the array
            
            while(found != NULL && !done){
                if ((found->getNameData()).compare(key) == 0) {
                    done = true;
                }
                if (!done)
                    found = found->getLink();
            }
            
           // found = dataArray[index].tail;
          //  cout << "Found the key at found: "<< found->getNameData() << endl;
            
        }
        else{
            cout << "Variable : " << key << " is not defined " << endl;
        }
            
       
        return found;
    }
    
    
    
    
    
    //helper function that does the hashing
    inline size_t HashTableCh::hash(string key)
    {
        int hashKey = 0;
        int temp;
        
        //useIndex = hashKey;
        
       // return (hashKey % SIZE);
        
        
        int stringLength = key.length();
        
        // declaring character array
        char char_array[stringLength + 1];
        
        // copying the contents of the
        // string to char array
        strcpy(char_array, key.c_str());
        
        //get the total sum of each characters ordinal
        //value, multiplied by position in array;
        for (int i = 1; i <= stringLength; i++) {
           // cout << char_array[i];
            temp = (int)char_array[i] * i;
            hashKey = hashKey + temp;
         }
        
        return (hashKey % SIZE);
        
    }
    
    
    
    void HashTableCh::printList()
    {
        HashNode *cursor;
        
        //Names
        cout << "Names of variables: \n";
        /*
        cursor = dataArray[useIndex].tail;
        cout << " " << cursor->getNameData() << " - " << cursor->getValueData() << ", ";
        
        cursor = cursor->getLink();
        cout << " " << cursor->getNameData() << " - " << cursor->getValueData() << ", ";

         */
        
         for (cursor = dataArray[useIndex].tail; cursor != NULL; cursor = cursor->getLink())
            cout << " " << cursor->getNameData() << " - " << cursor->getValueData() << ", ";
         
        
        //  cout << "Size of List: " << size() << endl;
        //  cout << "Head ptr: " << headPtrWeight->getName() << endl;
        cout << endl;
    }

}
