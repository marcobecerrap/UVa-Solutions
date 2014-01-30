// UVA-ID: #489
// "Hangman Judge"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

string EraseCharInString( string InputString, char c );

const int MAX_TRIES = 7;

int main( int argc, char *argv[] ){
  
  string InputWord;
  string InputLetters;
  
  int Case;
  cin >> Case;
  getline( cin, InputWord ); //Erase '\n'
  
  while( Case != -1 ){
    getline( cin, InputWord );
    getline( cin, InputLetters );
    
    int NTries = 0;

    while( InputLetters.length() > 0  && NTries < MAX_TRIES ){
      if( InputWord.find( InputLetters[ 0 ] ) != string::npos ){
	InputWord = EraseCharInString( InputWord, InputLetters[ 0 ] );
	InputLetters = EraseCharInString( InputLetters, InputLetters[ 0 ] );
      }
      else{
	NTries++;
	InputLetters = EraseCharInString( InputLetters, InputLetters[ 0 ] );
      }

      // cout << InputWord << " *** " << InputLetters << endl;

      if( InputWord.length() == 0 )
	break;
    }
    
    cout << "Round " << Case << endl;
    if( InputWord.length() == 0 )
      cout << "You win." << endl;
    else if( NTries < MAX_TRIES )
      cout << "You chickened out." << endl;
    else
      cout << "You lose." << endl;

    
    // Next Case
    cin >> Case;
    getline( cin, InputWord ); //Erase '\n'
  }
  
  return 0;
}

string EraseCharInString( string InputString, char c ){
  string RetString;

  for( int K = 0; K < InputString.length(); K++ )
    if( InputString[ K ] != c )
      RetString.push_back( InputString[ K ] );

  return RetString;
}
