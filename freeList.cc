#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
    head = inRAM;
    head[0] = size - 2;
    head[1] = 0;
}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;

// If head is not empty, and the size stored in head[0] is big enough to store the new allocation:
  if (head != NULL && head[0] >= size + 2) {

    long int newListSize = head[0] - (size + 2);

    loc = head + 2;
    loc[-2] = size;
    head = head + (size + 2);

    head[0] = newListSize;
    head[1] = 0;

  }

  return loc;
}

void
freeList::free_space( long int* location ) {

  long int* block = location - 2;
  block[1] = (long int)head;
  head = block;

}

void
freeList::coalesce_forward() {

      long int* current = head;

    while (current != NULL) {

        long int* next = (long int*)current[1];

        if (next != NULL && current + current[0] + 2 == next) {

            current[0] = current[0] + next[0] + 2;

            current[1] = next[1];

        } else {
            current = next;
        }
    }
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}
