// UVA-ID: 12289
// "One-Two-Three"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  string InputString;
  int Size;

  cin >> Size;

  for( int K = 0; K < Size; K++ ){
    cin >> InputString;
    
    // Case 3
    if( InputString.size() == 5 ){
      cout << 3 << endl;
      continue;
    }
    
    // Case 2
    if( (InputString[0] == 't' && InputString[ 1 ] == 'w') || (InputString[1] == 'w' && InputString[ 2 ] == 'o') || (InputString[0] == 't' && InputString[ 2 ] == 'o') ){
      cout << 2 << endl;
      continue;
    }
    
    cout << 1 << endl;
    
  }

  return 0;
}
