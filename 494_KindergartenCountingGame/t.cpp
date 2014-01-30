// UVA-ID: #494
// "Kindergarten Counting Game"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <sstream>
using namespace std;

int main( int argc, char *argv[] ){

  string InputString;

  while( getline( cin, InputString ) ){
    int WordCount = 0; // Word count
    int Flag = 0; // Is ON when we're reading a word
    istringstream InputStream( InputString ); 
    char c_aux;
    
    while( InputStream.get( c_aux ) ){ // Read the line
      if( Flag == 0 ){
	if( ( c_aux >='a' && c_aux <= 'z' ) || ( c_aux >='A' && c_aux <= 'Z' )  ){
	  WordCount++;
	  Flag ^= 1;
	}
      }
      else{
	if( !( ( c_aux >='a' && c_aux <= 'z' ) || ( c_aux >='A' && c_aux <= 'Z' ) ) )
	  Flag ^= 1;
      }
    }
    
    cout << WordCount << endl;    
  }

  return 0;
}
