// UVA-ID: #195
// "Anagram"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare( char a, char b );

int main( int argc, char *argv[] ){

  int NCases;
  cin >> NCases;

  string InputWord;
  string OutputWord;
  
  for( int K = 0; K < NCases; K++ ){
    cin >> InputWord;
    
    vector <char> Letters( InputWord.begin(), InputWord.end() );
    sort( Letters.begin(), Letters.end(), Compare );

    do{
      cout << string( Letters.begin(), Letters.end() ) << endl;
    } while( next_permutation( Letters.begin(), Letters.end(), Compare ) );
    
  }

  return 0;
}

bool Compare( char a, char b ){
  char t_a, t_b;

  if( a >= 'a' && a <= 'z' )
    t_a = a;
  else
    t_a = a - 'A' + 'a'; 

  if( b >= 'a' && b <= 'z' )
    t_b = b;
  else
    t_b = b - 'A' + 'a'; 

  if( t_a != t_b )
    return ( t_a < t_b );
  else 
    return ( a < b );
}
