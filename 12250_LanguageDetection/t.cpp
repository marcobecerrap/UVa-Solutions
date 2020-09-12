// UVA-ID: #12250
// "Language Detection"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  string InputString;
  int CaseCount = 0;

  while( getline( cin, InputString ) ){
    // Exit Condition
    if( InputString[ 0 ] == '#' )
      break;
    
    CaseCount++;
    cout << "Case " << CaseCount << ": ";
    
    if( InputString == "HELLO" )
      cout << "ENGLISH";
    else if( InputString == "HOLA" )
      cout << "SPANISH";
    else if( InputString == "HALLO" )
      cout << "GERMAN";
    else if( InputString == "BONJOUR" )
      cout << "FRENCH";
    else if( InputString == "CIAO" )
      cout << "ITALIAN";
    else if( InputString == "ZDRAVSTVUJTE" )
      cout << "RUSSIAN";
    else
      cout << "UNKNOWN";
    cout << endl;    
  }

  return 0;
}
