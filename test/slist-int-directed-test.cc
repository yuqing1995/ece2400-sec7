//========================================================================
// list-int-directed-test.cc
//========================================================================
// This file contains directed tests for ListInt-related functions.

#include "SListInt.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_1_push_front
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_1_push_front()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  int ref[] = { 10, 11, 12 };

  size_t i = 0;
  for ( int v : lst ) {
    UTST_ASSERT_INT_EQ( v, ref[i] );
    i += 1;
  }
}

//------------------------------------------------------------------------
// test_case_2_reverse
//------------------------------------------------------------------------
// A simple test case that tests reverse

void test_case_2_reverse()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);
  lst.reverse();

  int ref[] = { 12, 11, 10 };

  size_t i = 0;
  for ( int v : lst ) {
    UTST_ASSERT_INT_EQ( v, ref[i] );
    i += 1;
  }
}

//------------------------------------------------------------------------
// test_case_3_copy
//------------------------------------------------------------------------
// A simple test case that tests copying lists

void test_case_3_copy()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  // Call the copy constructor

  SListInt lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  int ref0[] = { 12, 11, 10 };

  size_t i = 0;
  for ( int v : lst0 ) {
    UTST_ASSERT_INT_EQ( v, ref0[i] );
    i += 1;
  }

  // Verify list 1

  int ref1[] = { 10, 11, 12 };

  size_t j = 0;
  for ( int v : lst1 ) {
    UTST_ASSERT_INT_EQ( v, ref1[j] );
    j += 1;
  }
}

//------------------------------------------------------------------------
// test_case_4_assign
//------------------------------------------------------------------------
// A simple test case that tests assigning lists

void test_case_4_assign()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  // Call the default constructor

  SListInt lst1;

  // Call the assignment operator

  lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  int ref0[] = { 12, 11, 10 };

  size_t i = 0;
  for ( int v : lst0 ) {
    UTST_ASSERT_INT_EQ( v, ref0[i] );
    i += 1;
  }

  // Verify list 1

  int ref1[] = { 10, 11, 12 };

  size_t j = 0;
  for ( int v : lst1 ) {
    UTST_ASSERT_INT_EQ( v, ref1[j] );
    j += 1;
  }
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_push_front();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_reverse();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_copy();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_4_assign();

  return 0;
}
