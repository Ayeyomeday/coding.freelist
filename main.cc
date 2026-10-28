#include "freeList.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

long int* RAM;

int main() {
    RAM = new long int[8192];

    freeList me(RAM, 8192);
    me.print();

    long int* addr1 = me.reserve_space(100);
    me.print();

    long int* addr2 = me.reserve_space(200);
    me.print();

    me.free_space(addr2);
    me.print();

    me.coalesce_forward();
    me.print();

    me.free_space(addr1);
    me.print();

    me.coalesce_forward();
    me.print();

    delete[] RAM;

    return 0;
}