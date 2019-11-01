//========================================================================
// slist-int-adhoc.c
//========================================================================

#include "SListInt.h"

int main( void )
{
  // Construct a list using default constructor

  SListInt list;

  // Push front three items

  list.push_front(12);
  list.push_front(11);
  list.push_front(10);

  // Print the list

  list.print();

  return 0;
}

