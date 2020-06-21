// UVA-ID: #673
// "Parenthesis Balance"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <stack>
using namespace std;

bool CheckCorrectness( string InputString );

int main( int argc, char *argv[] ){
  int nCases;
  cin >> nCases;
  string InputString;
  getline( cin , InputString ); // Clean last '\n'

  for( int K = 0; K < nCases; K++ ){
    getline( cin, InputString );

    if( CheckCorrectness( InputString ) == true )
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}

bool CheckCorrectness( string InputString ){
  stack <char> Parenthesis;

  if( InputString.size() == 0 )
    return true;
  
  for( int K = 0; K < InputString.size(); K++  ){
    if( InputString[ K ] == '(' ||  InputString[ K ] == '[' )
      Parenthesis.push( InputString[ K ] );
    else if( Parenthesis.empty() )
      return false;
    else if( InputString[ K ] == ')' && Parenthesis.top() == '(' )
      Parenthesis.pop();
    else if( InputString[ K ] == ']' && Parenthesis.top() == '[' )
      Parenthesis.pop();
    else
      return false;
  }
  if( Parenthesis.empty() )
    return true;
  else
    return false;
}
