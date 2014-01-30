// UVA-ID: 100
// "3n + 1"
// (cl) by mabp, sep-2011.
#include <iostream>

using namespace std;
typedef unsigned int UINT;

// Get the size of '3n+1' sequence of n
int Get3n1( UINT n ); 
// Inits an integer array to val
void i_InitArray1D( int arr[], int size, int val );

const int NOVAL    = -1;
const int COUNT_SZ = 1000000;
int Count[ COUNT_SZ]; // '3n+1' size storing


int main( int argc, char *argv[] ){
  UINT o1, o2; // Input order
  UINT n1, n2; // Ascend order
  int  max;    // max size of '3n+1' sequence in range

  i_InitArray1D( Count, COUNT_SZ, NOVAL );

  while ( cin >> o1 >> o2 ){
    max = 0;
    n1 = o1;
    n2 = o2;
    if( o1 > o2 ){ 
      n1 = o2;
      n2 = o1;
    }
    for( int aux, K=n1 ; K <= n2 ; K++ ){
      aux = Get3n1( K );
      if( max < aux )
	max = aux;
    }  
    cout << o1 << " " << o2 << " " << max << endl;
  }

  return 0;
}


int Get3n1( UINT n ){
  int aux;

  if( n < COUNT_SZ )
    if( Count[ n ] != NOVAL )
      return Count[ n ];

  if( n == 1 )
    aux = 1;
  else if( n%2 == 0 )
    aux = ( 1 + Get3n1( n/2 ) );
  else
    aux = ( 1 + Get3n1( 3*n + 1 ) );    
  
  if( n < COUNT_SZ )
    Count[ n ] = aux;
  return aux;
}


void i_InitArray1D( int arr[], int size, int val ){
  for( int i = 0 ; i < size ; i++ )
    arr[i] = val;
}

