// UVA-ID: 11547
// "Automatic Answer"
// (cl) by mabp, January-2014.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  int Size;
  cin >> Size;
  for( int K = 0; K < Size; K++ ){
    long Input;  
    cin >> Input;
    Input = ( ( ( Input * 567 / 9 ) + 7492 ) * 235 / 47 ) - 498;
    if( Input < 0 )
      Input *= -1;
    cout << ( ( Input / 10 ) % 10 ) << endl;
  }

  return 0;
}
