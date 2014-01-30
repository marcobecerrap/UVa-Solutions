// UVA-ID: #146
// "ID Codes"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main( int argc, char *argv[] ){

  string InputString;
  
  while( getline( cin, InputString ) ){
    // Exit Condition
    if( InputString.find( '#' ) != string::npos )
      break;
    
    vector <char> InputCode( InputString.begin(), InputString.end() );
    
    if( next_permutation( InputCode.begin(), InputCode.end() ) ){
      cout << string( InputCode.begin(), InputCode.end() ) << endl;
    }
    else
      cout << "No Successor" << endl;    
  }

  return 0;
}
