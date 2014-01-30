// UVA-ID: #11689
// "Soda Surpler"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int GetSodaBottles( int Bottles, int Bottles4Soda );

int main( int argc, char *argv[] ){

  int MyBottles;
  int FoundBottles;
  int Bottles4Soda;
  
  int NCases;
  cin >> NCases;
  
  for( int K = 0; K < NCases; K++ ){
    cin >> MyBottles >> FoundBottles >> Bottles4Soda;
    cout << GetSodaBottles( MyBottles + FoundBottles, Bottles4Soda ) << endl;
  }

  return 0;
}

int GetSodaBottles( int Bottles, int Bottles4Soda ){
  if( Bottles < Bottles4Soda )
    return 0;
  else
    return ( ( Bottles / Bottles4Soda ) + GetSodaBottles( ( Bottles % Bottles4Soda ) + ( Bottles / Bottles4Soda ), Bottles4Soda ) );
}
