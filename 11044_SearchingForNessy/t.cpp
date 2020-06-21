// UVA-ID: 11044
// "Searching For Nessy"
// (cl) by mabp, February-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  int Size;
  cin >> Size;

  for( int K = 0; K < Size; K++ ){
    int Cols, Rows;
    cin >> Cols >> Rows;

    if( Cols > Rows ){ // Cols < Rows
      int aux = Cols;
      Cols = Rows;
      Rows = aux;
    }

    // Trivial case
    if( Cols <= 2 ){
      cout << 0 << endl;
      continue;
    }
    else{
      Cols -= 2;
      Rows -= 2;
    }

    if( Rows <= 3 ){
      cout << 1 << endl;
      continue;
    }
    
    int SonarCount;
    int R_carry = ( ( Rows % 3 ) == 0 ) ? 0 : 1;
    int C_carry = ( ( Cols % 3 ) == 0 ) ? 0 : 1;
    SonarCount = ( Rows / 3 + R_carry ) * ( Cols / 3 + C_carry );
    cout << SonarCount << endl;
  }

  return 0;
}
