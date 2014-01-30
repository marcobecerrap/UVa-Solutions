// UVA-ID: #11150
// "Cola"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int GetTotalBottles( int NBottles );


int main( int argc, char *argv[] ){
  int NBottles;

  while( cin >> NBottles )
    cout << GetTotalBottles( NBottles ) << endl;

  return 0;
}

int GetTotalBottles( int NBottles ){
  if( NBottles == 2 )
    return 3;
  else if( NBottles == 1 )
    return 1;
  else if( NBottles == 0 )
    return 0;
  else
    return ( ( NBottles - ( NBottles % 3 ) ) + GetTotalBottles( ( NBottles / 3 ) + ( NBottles % 3 ) ) );
}
