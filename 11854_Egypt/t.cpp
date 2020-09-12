// UVA-ID: #11854
// "Egypt"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;
typedef unsigned long long ULONG;

void SwapNumbers( ULONG *A, ULONG *B );

int main( int argc, char *argv[] ){

  ULONG A, B, C;
  
  while( cin >> A >> B >> C ){
    // Exit Condition
    if( A == 0 && B == 0 && C == 0 )
      break;

    // Sorting (I only want the highest number to be C (hypotenuse))
    if( C < A )
      SwapNumbers( &A, &C );
    if( C < B )
      SwapNumbers( &B, &C );
    
    if( ( A*A + B*B ) == ( C*C ) )
      cout << "right" << endl;
    else
      cout << "wrong" << endl;    
  }

  return 0;
}

void SwapNumbers( ULONG *A, ULONG *B ){
  ULONG T = *A;
  *A = *B;
  *B = T;
}
