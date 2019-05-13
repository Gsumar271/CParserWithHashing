//
//   NodeStringList.h
//  Hashing
//
//  Created by Eugene Sumaryev on 5/8/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef _NodeStringList_h
#define _NodeStringList_h
#include <iostream>
#include <string>
#include "HashTableCh.h"
#include "NodeString.h"

namespace ClassProgram {
    //A class to hold a list of nodes
    class NodeStringList
    {
    public:
        NodeString* head;
        NodeStringList(){
            head = NULL;
        }
        
        void insert(NodeString::valueType& label)
        { ListInsert(label, head); }
        
        //return the value in the node
        //and remove the node from the list
        NodeString::valueType remove()
        {   NodeString* current;
            current = head;
            ListRemove(head);
            return current->getData();
        }
        
        bool isEmpty(){return head == NULL;}
        
        //searh for particular label
        bool search(NodeString::valueType& label)
        {
            NodeString *cursor;
            
            //if label is found, return TRUE, otherwise return FALSE
            for (cursor = head; cursor != NULL; cursor = cursor->getLink())
                if (label == cursor->getData())
                    return true;
            return false;
        }
    };
    
}

#endif /* _NodeStringList_h */
/*
 COM HERE IS OUR FIRST BORG PROGRAM
 COM WHAT A ROBUST LANGUAGE IT IS
 START
 VAR BORAMIR = 25
 VAR LEGOLAS = 101
 PRINT BORAMIR
 START
 LEGOLAS = 209
 VAR RIBOLAS = 5000
 LEGOLAS = 2000
 PRINT RIBOLAS
 PRINT LEGOLAS
 FINISH
 PRINT BORAMIR
 PRINT LEGOLAS
 FINISH
 */
