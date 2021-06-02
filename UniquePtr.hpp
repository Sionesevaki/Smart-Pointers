//
//  UniquePtr.hpp
//  smartpointers
//
//  Created by Sione on 4/12/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef UniquePtr_hpp
#define UniquePtr_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Foo.hpp"

using namespace std;

template <typename valuetype>

class UniquePtr{
public:
    UniquePtr() : UniquePtr{valuetype{}} {}
    UniquePtr(const valuetype& value) : _ptr{new valuetype{value}} {};
    ~UniquePtr() {delete _ptr;};
    template <typename... Args>
    UniquePtr(const Args&... args) : UniquePtr{valuetype{args...}}{}
    
    
    UniquePtr<valuetype>& operator = (const UniquePtr<valuetype>&) = delete;
    UniquePtr (const UniquePtr<valuetype>&) = delete;
    
    valuetype* operator->() const {return _ptr;};  // return poiter ref
    valuetype& operator*() const {return *_ptr;}; // return the object..
private:
    valuetype* _ptr = nullptr;
};


//******************************************


template <typename valuetype>

class UniquePtr<valuetype[]>{
public:
    UniquePtr(const int size) : _ptr{new valuetype[size]} {};
    ~UniquePtr() {delete[] _ptr;};
    
    
    UniquePtr<valuetype[]>& operator = (const UniquePtr<valuetype[]>&) = delete;
    UniquePtr (const UniquePtr<valuetype[]>&) = delete;
    
   valuetype& operator[] (int index) const { return _ptr[index];}
    
private:
    valuetype* _ptr = nullptr;
};





#endif /* UniquePtr_hpp */
