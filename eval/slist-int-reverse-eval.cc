//========================================================================
// slist-int-reverse-eval.c
//========================================================================
// This program evalutes the performance of ListInt::reverse by running
// multiple trials and averaging the elapsed run times.
//

#include <stdio.h>
#include <stdlib.h>
#include "SListInt.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// print_help
//------------------------------------------------------------------------
// Helper function to print the help message.

void print_help()
{
  printf(
    "usage: ./slist-int-reverse-eval <size>\n\n"
    "Evaluation program for ListInt::reverse\n\n"
    "positional arguments:\n"
    "  size        Size of the input array. It has to be within (0, 50000].\n"
  );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  int  size;
  int* eval_arr;

  // Check command line arguments

  if ( argc != 2 ) {
    printf("Invalid command line arguments!\n\n");
    print_help();
    return 1;
  }
  else {
    size = atoi( argv[1] );

    // Check size
    if ( size < 1 || size > 50000 ) {
      printf("Invalid size: %d\n\n", size );
      print_help();
      return 1;
    }
  }

  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so as to avoid precision issues with
  // gettimeofday().

  const int ntrials    = 5;
  const int nsubtrials = 1001;

  double elapsed;
  double elapsed_total = 0.0;

  // Fill list with decreasing values

  SListInt lst;
  for ( size_t i = 0; i < size; i++ )
    lst.push_front(i);

  printf( "Sort with size %d\n", size );

  // Timing loop

  for ( int i = 0; i < ntrials; i++ ) {

    // Start tracking time
    ece2400_timer_reset();

    // Execute nsubtrails
    for ( int j = 0; j < nsubtrials; j++ ) {
      lst.reverse();
    }

    // Stop tracking time
    elapsed = ece2400_timer_get_elapsed();

    // Accumulate result
    elapsed_total    += elapsed;

    printf( "Trial %d: elapsed time = %f second\n", i, elapsed );
  }

  // Calculate average elapsed time and peak heap usage

  double elapsed_avg    = elapsed_total    / ntrials;

  printf( "Average: elapsed time = %f second\n", elapsed_avg );

  // Verify the results. As long as nsubtrials is odd, then the result
  // should be just be a list of ints increasing from 0 to size.

  int ref = 0;
  for ( int v : lst ) {
    if ( v != ref ) {
      printf( "Error: List not reversed correctly!\n" );
      return 1;
    }
    ref += 1;
  }

  printf("Verfication passed\n");
  return 0;
}
