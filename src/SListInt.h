//========================================================================
// SListInt.h
//========================================================================
// Declarations for SListInt

#ifndef SLIST_INT_H
#define SLIST_INT_H

#include <cstddef>

class SListInt
{
  //----------------------------------------------------------------------
  // Constructor and destructor
  //----------------------------------------------------------------------

 public:

  SListInt();
  ~SListInt();

  //----------------------------------------------------------------------
  // Copy constructor and assignment operator
  //----------------------------------------------------------------------

 public:

  SListInt( const SListInt& lst );
  SListInt& operator=( const SListInt& lst );

  //----------------------------------------------------------------------
  // Member functions
  //----------------------------------------------------------------------

 public:

  void push_front( int v );
  void reverse();
  void print() const;

  //----------------------------------------------------------------------
  // Private member functions and fields
  //----------------------------------------------------------------------

 private:

  void copy( const SListInt& lst );
  void clear();

  struct Node                // nested struct declaration
  {
    int   value;
    Node* next_p;
  };

  Node* m_head_p;            // member field

  //----------------------------------------------------------------------
  // Nested iterator class
  //----------------------------------------------------------------------

 public:

  class Itr
  {
   public:
    Itr( Node* node_p );
    void next();
    int& get();
    bool eq( Itr itr ) const;

   private:
    Node* m_node_p;
  };

  //----------------------------------------------------------------------
  // Iterator begin/end member functions
  //----------------------------------------------------------------------

 public:

  const Itr begin() const;
  const Itr end() const;

};

//------------------------------------------------------------------------
// Overloaded operators for iterators
//------------------------------------------------------------------------

// Increment operator

SListInt::Itr  operator++( SListInt::Itr& itr, int );
SListInt::Itr& operator++( SListInt::Itr& itr );

// Dereference operator

int& operator*( SListInt::Itr& itr );

// Not-equal operator

bool operator!=( const SListInt::Itr& itr0, const SListInt::Itr& itr1  );

//------------------------------------------------------------------------
// Include inline definitions
//------------------------------------------------------------------------

#include "SListInt.inl"

#endif /* SLIST_INT_H */

