// UVA-ID: #11172
// "Relational Operator"
// (cl) by mabp, sep-2013.
#include <iostream>
using namespace std;
typedef long long LLONG;


int main( int argc, char *argv[] ){

  LLONG NumA;
  LLONG NumB;

  int nCases;  
  cin >> nCases;

  for( int K = 0; K < nCases; K++ ){
    cin >> NumA >> NumB;
    if( NumA > NumB )
      cout << ">" << endl;
    else if( NumA < NumB )
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }

  return 0;
}
