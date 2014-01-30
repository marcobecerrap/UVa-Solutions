// UVA-ID: #10107
// "What Is The Median?"
// (cl) by mabp, jan-2014.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ULONG;

int main( int argc, char *argv[] ){

  vector <ULONG> Numbers;
  ULONG Input;

  while ( cin >> Input ){
    Numbers.push_back( Input );
    sort( Numbers.begin(), Numbers.end() );
    
    int VectorSize = Numbers.size() - 1;
    if( ( VectorSize % 2 ) == 0 )
      cout << Numbers[ VectorSize / 2 ];
    else
      cout << ( int ) ( ( Numbers[ VectorSize / 2 ] + Numbers[ ( VectorSize / 2 )  + 1 ] ) / 2 );
    cout << endl;    
  }

  return 0;
}
