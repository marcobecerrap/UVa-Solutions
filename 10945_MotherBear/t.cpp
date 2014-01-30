// UVA-ID: #10945
// "Mother Bear"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

const string ValidChars  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string MirrorChars = "abcdefghijklmnopqrstuvwxyz";

string ClearString( string InputString );
bool IsPalindromeString( string InputString );


int main( int argc, char *argv[] ){

  string InputString;
  
  while( getline( cin, InputString ) ){
    
    if( InputString == "DONE" )
      break;
        
    // Preprocessing
    InputString = ClearString( InputString );
    
    // Palindrome Check
    bool IsPalindrome = IsPalindromeString( InputString );

    // Output
    if( IsPalindrome == true )
      cout << "You won't be eaten!" << endl;
    else
	cout << "Uh oh.." << endl;
  }

  return 0;
}


// Palindrome String Check
bool IsPalindromeString( string InputString ){

  for( int K = 0; K < ( InputString.length() / 2 ); K++ )
    if( InputString[ K ] == InputString[ InputString.length() - ( K + 1 ) ] );
    else
      return false;

  return true;
}

// Clears the InputString to only allocate valid characters
string ClearString( string InputString ){
  char InputChar;
  string RetString;
  for( int K = 0; K < InputString.length(); K++ ){
    InputChar = InputString[ K ];

    if( MirrorChars.find( InputChar ) != string::npos ){
      RetString.push_back( ValidChars[ MirrorChars.find( InputChar ) ] );
      continue;
    }
    
    if( ValidChars.find( InputChar ) != string::npos )
      RetString.push_back( InputChar );

  }
  return RetString;
}
