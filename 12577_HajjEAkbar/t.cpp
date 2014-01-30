// UVA-ID: #12577
// "Hajj-e-Akbar"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  string InputString;
  int CaseCount = 0;
  

  while( getline( cin, InputString ) ){
    CaseCount++;
    if( InputString[ 0 ] == '*' )
      break;

    cout << "Case " << CaseCount << ": ";
    if( InputString == "Hajj" )
      cout << "Hajj-e-Akbar" << endl;
    if( InputString == "Umrah" )
      cout << "Hajj-e-Asghar" << endl;
  }

  return 0;
}
