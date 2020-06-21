// UVA-ID: 12149
// "Feyman"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  unsigned long long Num;
  while( cin >> Num ){
    if( Num == 0 )
      break;
    
    cout << ( ( Num * ( Num + 1 ) * ( 2 * Num + 1) ) / 6 ) << endl;
  }

  return 0;
}
