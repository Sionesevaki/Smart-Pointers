//
//  SharedPtr.hpp
//  smartpointers
//
//  Created by Sione on 4/12/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef SharedPtr_hpp
#define SharedPtr_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Foo.hpp"

using namespace std;

template <typename valuetype>

class SharedPtr{
public:
    SharedPtr() : SharedPtr{valuetype{}} {}
    SharedPtr(const valuetype& value) : _ptr{new valuetype{value}}, countPtr{new int{1}} {};
    ~SharedPtr()
    {
        countPtr--;
        
        if(countPtr == 0)
        {
            delete countPtr;
            delete _ptr;
        }
    };
    
    template <typename... Args>
    SharedPtr(const Args&... args) : SharedPtr{valuetype{args...}}{}
    
    
    SharedPtr<valuetype>& operator = (const SharedPtr<valuetype>& rhs)
    {
        if(this->_ptr != rhs->_ptr)
        {
            *countPtr--;
            
            if(*countPtr == 0)
            {
                delete _ptr;
                delete countPtr;
            }
        }
    
        _ptr = rhs._ptr;
        countPtr = rhs->countPtr;
        *countPtr++;
        
        return *this;
    };
    
    SharedPtr(const SharedPtr<valuetype>& rhs)
    {
        _ptr = rhs._ptr;
        countPtr = rhs.countPtr;
        countPtr++;
    };
    
    valuetype* operator->() const {return _ptr; };  // return poiter ref
    valuetype& operator*() const {return *_ptr; }; // return the object..
private:
    valuetype* _ptr = nullptr;
    int *countPtr = nullptr;
};


//******************************************


template <typename valuetype>

class SharedPtr<valuetype[]>{
public:
    SharedPtr(const int size) : _ptr{new valuetype[size]} {};
    ~SharedPtr() {delete[] _ptr;};
    
    
    SharedPtr<valuetype[]>& operator = (const SharedPtr<valuetype[]>& rhs)
    {
        if(this->_ptr != rhs->_ptr)
        {
            *countPtr--;
            
            if(*countPtr == 0)
            {
                delete[] _ptr;
                delete countPtr;
            }
        }
        
        _ptr = rhs._ptr;
        countPtr = rhs._ptr;
        *countPtr++;
        
        return *this;
    }
    SharedPtr(const SharedPtr<valuetype[]>& rhs)
    {
        _ptr = rhs._ptr;
        countPtr = rhs.countPtr;
        countPtr++;
    }
    
    valuetype& operator[] (int index) const { return _ptr[index];}
    
private:
    valuetype* _ptr = nullptr;
    int *countPtr = nullptr;
};







#endif /* SharedPtr_hpp */
