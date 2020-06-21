// UVA-ID: 12896
// "Mobile SMS"
// (cl) by mabp, January-2015.
#include <iostream>
#include <string>
using namespace std;

int main( int argc, char *argv[] ){

  string Keyboard[ 10 ];
  Keyboard[ 0 ] = " ";
  Keyboard[ 1 ] = ".,?\"";
  Keyboard[ 2 ] = "abc";
  Keyboard[ 3 ] = "def";
  Keyboard[ 4 ] = "ghi";
  Keyboard[ 5 ] = "jkl";
  Keyboard[ 6 ] = "mno";
  Keyboard[ 7 ] = "pqrs";
  Keyboard[ 8 ] = "tuv";
  Keyboard[ 9 ] = "wxyz";

  int Size;
  cin >> Size;
  
  for( int K = 0; K < Size; K++ ){
    int MsgSize;
    cin >> MsgSize;

    int Button[ MsgSize ];    
    for( int P = 0; P < MsgSize; P++ )
      cin >> Button[ P ];

    int Press;
    for( int P = 0; P < MsgSize; P++ ){
      cin >> Press;      
      cout << Keyboard[ Button[ P ] ][ ( Press % ( Keyboard[ Button[ P ] ].size() + 1 ) ) - 1 ];      
    }
    cout << endl;

  }

  return 0;
}
