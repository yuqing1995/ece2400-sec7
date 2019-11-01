//========================================================================
// SListInt.cc
//========================================================================
// Implementation for ListInt

#include <cstdio>
#include <cassert>
#include "SListInt.h"

//------------------------------------------------------------------------
// SListInt Default Constructor
//------------------------------------------------------------------------

SListInt::SListInt()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement constructor
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt()
{
  clear();
}

//------------------------------------------------------------------------
// SListInt Copy Constructor
//------------------------------------------------------------------------

SListInt::SListInt( const SListInt& lst )
{
  copy(lst);
}

//------------------------------------------------------------------------
// SListInt Overloaded Assignment Operator
//------------------------------------------------------------------------

SListInt& SListInt::operator=( const SListInt& lst )
{
  clear();
  copy(lst);
  return *this;
}

//------------------------------------------------------------------------
// SListInt::push_front
//------------------------------------------------------------------------

void SListInt::push_front( int v )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement push_front
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  Node* new_node_p   = new Node;
  new_node_p->value  = v;
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListInt::reverse
//------------------------------------------------------------------------

void SListInt::reverse()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  size_t size = 0;
  for ( int v: *this ) {
    v = v; // avoid unused variable warning
    size++;
  }

  int* tmp = new int[size];

  size_t i = 0;
  for ( int v : *this )
    tmp[i++] = v;

  size_t j = size-1;
  for ( int& v : *this )
    v = tmp[j--];

  delete[] tmp;
}

//------------------------------------------------------------------------
// SListInt::print
//------------------------------------------------------------------------

void SListInt::print() const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement print
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  for ( int v : *this )
    std::printf( "%d ", v );
  std::printf("\n");
}

//------------------------------------------------------------------------
// SListInt::copy
//------------------------------------------------------------------------

void SListInt::copy( const SListInt& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement copy
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Node* curr_p = lst.m_head_p;
  // if ( curr_p == nullptr )
  //   return;
  //
  // m_head_p = new Node;
  // m_head_p->value  = curr_p->value;
  // m_head_p->next_p = nullptr;
  // curr_p = curr_p->next_p;
  //
  // Node* tail_p = m_head_p;
  // while ( curr_p != nullptr ) {
  //   Node* new_node_p = new Node;
  //   new_node_p->value  = curr_p->value;
  //   new_node_p->next_p = nullptr;
  //   tail_p->next_p = new_node_p;
  //   tail_p = new_node_p;
  //   curr_p = curr_p->next_p;
  // }
}

//------------------------------------------------------------------------
// SListInt::clear
//------------------------------------------------------------------------

void SListInt::clear()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement clear
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }
}

//------------------------------------------------------------------------
// SListInt::Itr Constructor
//------------------------------------------------------------------------

SListInt::Itr::Itr( Node* node_p )
{
  m_node_p = node_p;
}

//------------------------------------------------------------------------
// SListInt::Itr::next
//------------------------------------------------------------------------

void SListInt::Itr::next()
{
  assert( m_node_p != nullptr );
  m_node_p = m_node_p->next_p;
}

//------------------------------------------------------------------------
// SListInt::Itr::get
//------------------------------------------------------------------------

int& SListInt::Itr::get()
{
  assert( m_node_p != nullptr );
  return m_node_p->value;
}

//------------------------------------------------------------------------
// SListInt::Itr::eq
//------------------------------------------------------------------------

bool SListInt::Itr::eq( Itr itr ) const
{
  return ( m_node_p == itr.m_node_p );
}

//------------------------------------------------------------------------
// SListInt::Itr::begin
//------------------------------------------------------------------------

const SListInt::Itr SListInt::begin() const
{
  return Itr(m_head_p);
}

//------------------------------------------------------------------------
// SListInt::Itr::end
//------------------------------------------------------------------------

const SListInt::Itr SListInt::end() const
{
  return Itr(nullptr);
}

//------------------------------------------------------------------------
// SListInt::Iter postfix increment operator (itr++)
//------------------------------------------------------------------------

SListInt::Itr operator++( SListInt::Itr& itr, int )
{
  SListInt::Itr itr_tmp = itr;
  itr.next();
  return itr_tmp;
}

//------------------------------------------------------------------------
// SListInt::Iter prefix increment operator (++itr)
//------------------------------------------------------------------------

SListInt::Itr& operator++( SListInt::Itr& itr )
{
  itr.next();
  return itr;
}

//------------------------------------------------------------------------
// SListInt::Iter dereference operator (*itr)
//------------------------------------------------------------------------

int& operator*( SListInt::Itr& itr )
{
  return itr.get();
}

//------------------------------------------------------------------------
// SListInt::Iter not-equal operator (itr0 != itr1)
//------------------------------------------------------------------------

bool operator!=( const SListInt::Itr& itr0, const SListInt::Itr& itr1  )
{
  return !itr0.eq( itr1 );
}
