// UVA-ID: #10783
// "Odd Sum"
// (cl) by mabp, sep-2013.
#include <iostream>
using namespace std;

void SwapNumbers( int *NA, int *NB );

int main( int argc, char *argv[] ){

  int nCases;
  int NumA;
  int NumB;
  int K; // Wer'e going to sum the odd numbers from 1 to (2K+1)
  int Offset;
  int SUM;
  cin >> nCases; // Number os cases
  
  for( int T = 0; T < nCases; T++ ){
    cin >> NumA;
    cin >> NumB;
    
    if( NumA > NumB )
      SwapNumbers( &NumA, &NumB );

    if( NumB == 0 ){ // Trivial case
      cout << "Case " << ( T + 1 ) << ": 0" << endl;
      continue;
    }

    // Acondition the Input to have an interval closed by two odd numbers.
    if( ( NumA % 2 ) == 0 )
      NumA += 1;
    if( ( NumB % 2 ) == 0 )
      NumB -= 1;    
    
    Offset = NumA - 1;
    NumA -= Offset;
    NumB -= Offset;
    K = ( NumB - 1 ) / 2;

    SUM = ( K * K ) + ( 2 * K ) + 1 + ( Offset * ( K + 1 ) );
    
    cout << "Case " << ( T + 1 ) << ": " << SUM << endl;
    
  }

  return 0;
}

void SwapNumbers( int *NA, int *NB ){
  int K = *NA;
  *NA = *NB;
  *NB = K;
}
