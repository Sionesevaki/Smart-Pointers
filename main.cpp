//
//  main.cpp
//  smartpointers
//
//  Created by Sione on 4/12/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include <iostream>
#include <string>
#include "UniquePtr.hpp"
#include "Foo.hpp"
#include "SharedPtr.hpp"

using namespace std;

struct Fraction
{
    Fraction(int nn , int dd): n{nn}, d{dd} {}
    int n = 0;
    int d = 1;
};

ostream& operator << (ostream& strm, const Fraction& f)
{
    strm << f.n << "/" << f.d;
    return strm;
}

int main(int argc, const char * argv[])
{
    UniquePtr<Foo> p1;
    
    cout << "SERIAL: " << p1->serial() << endl;
    cout << "SERIAL: " << (*p1).serial() << endl;
    
    UniquePtr<Foo> p2{"P2"};
    cout << *p2 << endl;
    
    
    UniquePtr<Fraction> fptr{1,2};
    cout << *fptr << endl;
    
    
    UniquePtr<Foo[]> fooarr{5};
    for(int i = 0; i < 5; i++)
    {
        cout << "FOO #: " << fooarr[i].serial() << endl;
    }
    
    cout << "**** SHARED PTR ****" << endl;
    SharedPtr<Foo> sp1{"SHRPTR 1"};
    cout << *sp1 << endl;
    {
        SharedPtr<Foo> sp2{sp1};
        SharedPtr<Foo> sp3;
        sp3 = sp2;
    }
    cout << "Copy was deleted" << endl;
    
    
    return 0;
}
