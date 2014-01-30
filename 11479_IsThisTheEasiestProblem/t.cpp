// UVA-ID: #11479
// "Is This The Easiest Problem"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

void IntSwap( long long *a, long long *b );


int main( int argc, char *argv[] ){

  int NCases = 0;
  cin >> NCases;
  
  long long n1, n2, n3;
  for( int K = 0; K < NCases; K++ ){
    cin >> n1 >> n2 >> n3;
    
    // Sorting... 
    if( n1 > n2 ) 
      IntSwap( &n1, &n2 );
    if( n2 > n3 ) 
      IntSwap( &n2, &n3 );
    if( n1 > n2 ) 
      IntSwap( &n1, &n2 );
    
    // OUTPUT:
    cout << "Case " << ( K + 1 ) << ": ";
    if( ( n1 + n2 ) <= n3  || n1 <= 0)
      cout << "Invalid";
    else if( n1 == n2 && n2 == n3 )
      cout << "Equilateral";
    else if( n1 == n2 || n2 == n3 )
      cout << "Isosceles";
    else
      cout << "Scalene";
    
    cout << endl;    
  }
  
  return 0;
}

void IntSwap( long long *a, long long *b ){
  long long t = *a;
  *a = *b;
  *b = t;
}
