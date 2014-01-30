// UVA-ID: #458
// "The Decoder"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  string InputString;
  
  while( cin >> InputString ){
    for( int K = 0; K < InputString.length(); K++ )
      cout << (char) ( InputString[ K ] - 7 );
    cout << endl;
  }

  return 0;
}
