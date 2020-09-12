// UVA-ID: #10082
// "WERTYU"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

string Keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main( int argc, char *argv[] ){
  string InputString;

  while( getline( cin, InputString ) ){
    string RetString;

    for( int K = 0; K < InputString.length(); K++ ){
      if( Keyboard.find( InputString[ K ] ) != string::npos )
	RetString.push_back( Keyboard[ Keyboard.find( InputString[ K ] ) - 1 ] );
      else
	RetString.push_back( InputString[ K ] );      
    }
    
    cout << RetString << endl;
  }

  return 0;
}
