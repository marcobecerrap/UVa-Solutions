// UVA-ID: 278
// "Chess"
// (cl) by mabp, January-2014.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  char InputChar;
  int InputRows, InputCols;
  int Size;
  cin >> Size;
  
  for( int K = 0; K < Size; K++ ){
    cin >> InputChar >> InputRows >> InputCols;

    int MaxPieces;
    switch( InputChar ){
    case 'Q':
    case 'r':
      MaxPieces = ( InputRows < InputCols ) ? InputRows : InputCols;
      break;
    case 'K':
      MaxPieces = ( ( InputRows / 2 ) + ( InputRows % 2 ) ) * ( ( InputCols / 2 ) + ( InputCols % 2 ) );
      break;
    case 'k':
      MaxPieces = ( InputRows * InputCols / 2 ) + ( ( InputRows * InputCols ) % 2 );
      break;
    }
    
    cout << MaxPieces << endl;
  }

  return 0;
}
