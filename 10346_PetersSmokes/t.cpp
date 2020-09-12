// UVA-ID: #10346
// "Peter's Smokes"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

typedef unsigned long int ULONG;

int main( int argc, char *argv[] ){

  ULONG Cigarettes, Deal;
  ULONG Total;

  while( cin >> Cigarettes >> Deal ){
    Total = Cigarettes;
    while( ( Cigarettes / Deal ) > 0 ){
      Total += ( Cigarettes / Deal );
      Cigarettes = ( Cigarettes / Deal ) + ( Cigarettes % Deal );
    }    
    
    cout << Total << endl;
  }

  return 0;
}
