// UVA-ID: #10812
// "Beat The Spread"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  string InputString;

  int NCases;
  cin >> NCases;

  int isum, idiff, ix1, ix2;
  double dsum, ddiff, dx1, dx2;
  int CaseCount = 0;
  while( cin >> isum >> idiff ){
    CaseCount++;
    
    dsum =  (double) isum;
    ddiff = (double) idiff;
    
    // Solving "Integer"
    ix1 = ( isum + idiff ) / 2;
    ix2 = ( isum - idiff ) / 2;

    // Solving "Double"
    dx1 =  ( dsum + ddiff ) / 2;
    dx2 =  ( dsum - ddiff ) / 2;


    if( dx1 < 0 || dx2 < 0  || dx1 != ix1 || dx2 != ix2 )
      cout << "impossible" << endl;
    else
      cout << ix1 << " " << ix2 << endl;
    
    if( CaseCount == NCases )
      break;
  }

  return 0;
}
