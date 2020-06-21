// UVA-ID: 10849
// "Move The Bishop"
// (cl) by mabp, January-2015.
#include <iostream>
#include <cmath>
using namespace std;

int main( int argc, char *argv[] ){


  int Size;
  cin >> Size;
  
  for( int K = 0; K < Size; K++ ){

    int NewCases;
    int BoardSize;
    cin >> NewCases;
    cin >> BoardSize;

    int Px_0, Py_0, Px_1, Py_1;

    for( int P = 0; P < NewCases; P++ ){

      cin >> Px_0 >> Py_0 >> Px_1 >> Py_1;

      if( Px_0 == Px_1 && Py_0 == Py_1){
	cout << 0 << endl;
	continue;
      }
      
      if( ( Px_1 > BoardSize || Px_1 < 1 || Py_1 > BoardSize || Py_1 < 1 ) || ( ( ( Px_0 + Py_0 ) % 2 ) != ( ( Px_1 + Py_1 ) % 2 ) ) ){
	cout << "no move" << endl;
	continue;
      }

      if( abs( Px_1 - Px_0 ) == abs( Py_1 - Py_0 ) )
	cout << 1 << endl;
      else
	cout << 2 << endl;
    }
  }
  
  return 0;
}
