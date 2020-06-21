// UVA-ID: #401
// "Palindromes"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

const string ValidChars  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const string MirrorChars = "A***3**HIL*JM*O***2TUVWXY51SE*Z**8*";

string ClearString( string InputString );
bool IsPalindromeString( string InputString );
bool IsMirrorString( string InputString );


int main( int argc, char *argv[] ){

  string InputString;
  
  while( getline( cin, InputString ) ){
        
    // Preprocessing
    InputString = ClearString( InputString );
    
    // Palindrome Check
    bool IsPalindrome = IsPalindromeString( InputString );

    // Mirror Check
    bool IsMirror = IsMirrorString( InputString );
    
    // Output
    if( IsPalindrome == true ){
      if( IsMirror == true )
	cout << InputString << " -- is a mirrored palindrome." << endl;
      else
	cout << InputString << " -- is a regular palindrome." << endl;
    }
    else if( IsMirror == true )
      cout << InputString << " -- is a mirrored string." << endl;
    else
	cout << InputString << " -- is not a palindrome." << endl;
    cout << endl;
  }

  return 0;
}

// Mirror String Check
bool IsMirrorString( string InputString ){
  
  for( int K = 0; K < InputString.length(); K++ )
    if( MirrorChars.find( InputString[ K ] ) == string::npos )
      return false;

  for( int K = 0; K < ( InputString.length() / 2 ); K++ )
    if( ValidChars.find( InputString[ K ] ) == MirrorChars.find( InputString[ InputString.length() - ( K + 1 ) ] ) );
    else
      return false;
  
  return true;
  
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
    if( ValidChars.find( InputChar ) != string::npos )
      RetString.push_back( InputChar );
    else
      break;
  }
  return RetString;
}
