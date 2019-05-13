//
//  HashNode.h
//  Hashing
//
//  Created by Eugene Sumaryev on 4/28/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

#include <cstdlib>  //
#include <set>      //
#include <string>
#include <iostream>

using namespace std;

namespace ClassProgram
{
    class HashNode
    {
    public:
        // MEMBER CONSTANTS
        typedef string valueTypeName;
        typedef double valueTypeValue;
        
        // CONSTRUCTORS
        HashNode(){};
        HashNode(valueTypeName& initNameData, valueTypeValue& initValueData)
        {nameData=initNameData; valueData=initValueData; link=NULL;};
        
        ~HashNode(){};
        
        // MODIFICATION MEMBER FUNCTIONS
        void setNameData(valueTypeName& newNameData){nameData = newNameData;}
        void setValueData(valueTypeValue& newValueData){valueData = newValueData;}
        void setLink(HashNode* node){ link = node;}
        
        // CONSTANT MEMBER FUNCTIONS
        const valueTypeName getNameData(){ return nameData; }
        const valueTypeValue getValueData(){ return valueData; }
        HashNode* getLink() { return link; }
        
    private:
        valueTypeName nameData;
        valueTypeValue valueData;
        HashNode* link;
    };
}


#endif /* HashNode_h */
