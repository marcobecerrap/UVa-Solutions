// UVA-ID: 696
// "How Many Knights"
// (cl) by mabp, January-2014.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  int InputRows, InputCols;
  
  while( cin >> InputRows >> InputCols ){

    if( InputRows == 0 && InputCols == 0 )
      break;
    
    int Knights = 0;

    if( InputRows <=0 || InputCols <=0 )
      Knights = 0;
    else if( InputRows == 1 || InputCols == 1 )
      Knights = InputRows * InputCols;
    else if( InputRows == 2 || InputCols == 2 ){
      int aux_rows, aux_cols, aux_carry;
      aux_rows = 2;
      aux_cols = ( InputRows == 2 ) ? InputCols : InputRows;
      
      aux_carry = aux_cols % 2;
      aux_cols /= 2;

      if( ( aux_cols % 2 ) == 1 )
	Knights = 4 * ( ( aux_cols / 2 ) + 1 );
      else
	Knights = 2 * ( aux_cols + aux_carry );
    }
    else    
      Knights = ( InputRows * InputCols / 2 ) + ( ( InputRows * InputCols ) % 2 );
    
    cout << Knights << " knights may be placed on a " << InputRows << " row " << InputCols<< " column board." << endl;

  }

  return 0;
}
