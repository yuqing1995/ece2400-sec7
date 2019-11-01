//========================================================================
// slist-int-adhoc.c
//========================================================================

#include "SListInt.h"
#include <cstdio>
#include <cassert>
int main( void )
{
  // Construct a list using default constructor

  SListInt list;

  // Push front three items

  list.push_front(12);
  list.push_front(11);
  list.push_front(10);
  for ( auto itr = list.begin(); itr != list.end(); itr++ ){
      printf( "%d ", *itr );
  }
  printf( "\n" );
  list.reverse();

  // Print the list

  list.print();

  return 0;
}

